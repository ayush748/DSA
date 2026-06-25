#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
node* insertion(node* root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        return newnode;
    }
    if(data < root->data){
        root->left=insertion(root->left,data);
    }else{
        root->right=insertion(root->right,data);
    }
    return root;
}
node* build(vector<int>arr,int i,int ub){
    if(i==arr.size() || arr[i]>ub){
        return NULL;
    }
    node* root=new node(arr[i++]);
    root->left=build(arr,i,root->data);
    root->right=build(arr,i,ub);
}
int main(){
    return 0;
}