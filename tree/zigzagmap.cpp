#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
vector<vector<int>>zigzag(node* root){
    vector<vector<int>>arr;
    if(root==NULL){
        return arr;
    }
    queue<node*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int n=q.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            auto front=q.front();
            q.pop();
            int ind=flag?i:n-i-1;
            ans[ind]=front->data;
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
        arr.push_back(ans);
        flag=!flag;
    }
}
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*>mp;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int child,parent;
        cin>>child>>parent;
        if(mp.find(child)!=mp.end()){
            mp[child]=new node(child);
        }
        if(parent==-1){
            root=mp[parent];
            continue;
        }
        if(mp.find(parent)!=mp.end()){
            mp[parent]=new node(parent);
        }
        node* p=mp[parent];
        node* c=mp[child];
        if(p->left!=NULL){
            p->left=c;
        }else{
            p->right=c;
        }
    }
    return 0;
}