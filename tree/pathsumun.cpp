#include<iostream>
#include<vector>
#include<unordered_map>
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
int solve(node* root,int sum){
    if(root==NULL){
        return 0;
    }
    int l=max(0,solve(root->left,sum));
    int r=max(0,solve(root->right,sum));
    sum=max(sum,root->data+l+r);
    return root->data+max(l,r);
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
            continue;
        }
        if(parent==-1){
            root=mp[child];
        }
        if(mp.find(parent)!=mp.end()){
            mp[parent]=new node(parent);
        }
        node* p=mp[parent];
        node* c=mp[child];
        if(p->left==NULL){
            p->left=c;
        }else{
            p->right=c;
        }
    }
    int sum=INT_MIN;
    int ans=solve(root,sum);
    cout<<sum;
    return 0;
}