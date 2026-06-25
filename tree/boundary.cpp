#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
bool isleaf(node* root){
    return root->left==NULL && root->right==NULL;
}
void addleftboundary(node* root,vector<int>& res){
    node* curr=root->left;
    while(curr){
        if(!isleaf(curr)){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr=curr->left;
        }
        else{
            curr=curr->right;
        }
    }
}
void addRight(node* root,vector<int>& res){
    node* curr=root->right;
    stack<int> st;
    while(curr){
        if(!isleaf(curr)){
            st.push(curr->data);
        }
        if(curr->right){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}
void addLeaf(node* root,vector<int>& res){
    if(root==NULL){
        return;
    }
    if(isleaf(root)){
        res.push_back(root->data);
        return;
    }
    addLeaf(root->left,res);
    addLeaf(root->right,res);
}
vector<int> solve(node* root){
    vector<int> res;
    if(root==NULL){
        return res;
    }
    if(!isleaf(root)){
        res.push_back(root->data);
    }
    addleftboundary(root,res);
    addLeaf(root,res);
    addRight(root,res);
    return res;
}
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*> mp;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int child,parent;
        cin>>child>>parent;
        if(mp.find(child)==mp.end()){
            mp[child]=new node(child);
        }
        if(parent==-1){
            root=mp[child];
            continue;
        }
        if(mp.find(parent)==mp.end()){
            mp[parent]=new node(parent);
        }
        node* p=mp[parent];
        node* c=mp[child];
        if(p->left==NULL){
            p->left=c;
        }
        else{
            p->right=c;
        }
    }
    vector<int> res=solve(root);
    for(int x:res){
        cout<<x<<" ";
    }
    return 0;
}