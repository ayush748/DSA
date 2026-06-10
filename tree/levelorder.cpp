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
node* createTree(node* &root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        root=newnode;
        return root;
    }
    if(root->data>data){
        root->left=createTree(root->left,data);
    }else{
        root->right=createTree(root->right,data);
    }
    return root;
}
void levelOrder(node* &root){
    if(root==NULL){
        return ;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        cout<<front->data;
        if(front->left!=NULL){
            q.push(front->left);
        }
        if(front->right!=NULL){
            q.push(front->right);
        }
    }
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
    levelOrder(root);
    return 0;
}