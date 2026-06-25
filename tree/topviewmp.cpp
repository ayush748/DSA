#include<iostream>
#include<vector>
#include<queue>
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
vector<int>solve(node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    unordered_map<int,int>mp;
    queue<pair<int,node*>>q;
    q.push({0,root});
    while(!q.empty()){
        auto frontnode=q.front();
        q.pop();
        int vindex=frontnode.first;
        node* p=frontnode.second;
        if(mp.find(vindex)==mp.end()){
            mp[vindex]=p->data;
        }
        if(p->left!=NULL){
            q.push({vindex-1,p->left});
        }
        if(p->right!=NULL){
            q.push({vindex+1,p->right});
        }
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
            root=mp[child];
        }
        if(mp.find(child)!=mp.end()){
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

    return 0;
}