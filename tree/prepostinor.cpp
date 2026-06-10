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
// pre
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}
// inorder
void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
// postorder
void postorder(node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
void convertarray(node* &root,vector<int>arr){
    
}
int main(){
    int n;
    cin>>n;
    while(n--){
        createTree();
    }
    
    return 0;
}