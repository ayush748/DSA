#include<iostream>
#include<vector>
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
bool solve(node* root,vector<int>&arr,int x){
    if(root==NULL){
        return false;
    }
    arr.push_back(root->data);
    if(root->data==x){
        return true;
    }
    if(solve(root->left,arr,x) || solve(root->right,arr,x)){
        return false;
    }
    arr.pop_back();
    return false;
}
int main(){
    node* root=createTree();
    vector<int>arr;

    solve(root,arr,7);

    return 0;
}