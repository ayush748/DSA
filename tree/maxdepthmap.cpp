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
        this->left=NULL;
        this->right=NULL;
    }
};
int maxdepth(node* root){
    if(root==NULL){
        return 0;
    }
    int l=maxdepth(root->left);
    int r=maxdepth(root->right);
    int ans=max(l,r);
    return ans+1;
}
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*>mp;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int ch,pa;
        cin>>ch>>pa;
        if(mp.find(ch)!=mp.end()){
            mp[ch]=new node(ch);
        }
        if(pa==-1){
            root=mp[ch];
        }else{
            if(mp.find(pa)!=mp.end()){
                mp[pa]=new node(pa);
            }
            node *p=mp[pa];
            if(p->left==NULL){
                p->left=mp[ch];
            }else{
                p->right=mp[ch];
            }
        }
    }
    cout<<maxdepth(root);
    return 0;
}