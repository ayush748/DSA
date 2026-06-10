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
node* createTree(node* &root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        return root;
    }
    if(root->data>data){
        root->left=createTree(root->left,data);
    }else{
        root->right=createTree(root->right,data);
    }
    return root;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    node* root=NULL;
    for(int i=0;i<n;i++){
        createTree(root,arr[i]);
    }
    
    
    return 0;
}