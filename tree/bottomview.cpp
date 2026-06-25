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
node* createTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* root=new node(data);
    root->left=createTree();
    root->right=createTree();
    return root;
}
vector<int>solve(node* root){
    vector<int>arr;
    if(root==NULL){
        return arr;
    }
    queue<pair<int,node*>>q;
    unordered_map<int,int>mp;
    q.push({0,root});
    while(!q.empty()){
        auto frontnode=q.front();
        q.pop();
        int vindex=frontnode.first;
        node* parent=frontnode.second;
        mp[vindex]=parent->data;
        if(parent->left!=NULL){
            q.push({vindex-1,parent->left});
        }
        if(parent->right!=NULL){
            q.push({vindex+1,parent->right});
        }
    }
}

int main(){

    return 0;
}