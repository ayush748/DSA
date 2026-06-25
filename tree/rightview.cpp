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
void rightView(node* root,int level,vector<int>&ans){
    if(root==NULL){
        return ;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    rightView(root->right,level+1,ans);
    rightView(root->left,level+1,ans);
}
int main(){
    int n;
    cin>>n;
    node* root=NULL;
    
    root=createTree();
    
    int level=0;
    vector<int>ans;
    rightView(root,level,ans);
    return 0;
}