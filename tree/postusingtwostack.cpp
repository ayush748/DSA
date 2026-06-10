#include<iostream>
#include<vector>
#include<stack>
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
node* btree(node* root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        root=newnode;
        return root;
    }
    if(root->data>data){
        root->left=btree(root->left,data);
    }else if(root->data<data){
        root->right=btree(root->right,data);
    }
    return root;
}
void postOrder(node* &root,vector<int>ans){
    if(root==NULL){
        return ;
    }
    stack<node*>st1;
    stack<node*>st2;
    st1.push(root);
    st1.push(root);
    while(!st1.empty()){
        root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){
            st1.push(root->left);
        }
        if(root->right!=NULL){
            st1.push(root->right);
        }
    }
    while (!st2.empty())
    { 
        ans.push_back(st2.top()->data);
        st2.pop();
    }
    


}
int main(){
    int n;
    cin>>n;

    return 0;
}