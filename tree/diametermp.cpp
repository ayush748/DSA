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
int solve(node* root,int maxi){
    if(root==NULL){
        return 0;
    }
    int left=solve(root->left,maxi);
    int right=solve(root->right,maxi);
    maxi=max(maxi,right+left);
    return  max(left,right)+1;
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
    int ans=INT_MIN;
    cout<<solve(root,ans);

    return 0;
}