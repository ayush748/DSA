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
    if(data<root->data){
        root->left=insertion(root->left,data);
    }else{
        root->right=insertion(root->right,data);
    }
    return root;
}
node* insertbst(node* root,int val){
    if(root==NULL){
        node* root=new node(val);
        return root;
    }
    node* curr=root;
    while(true){
        if(curr->data<=val){
            if(curr->right!=NULL){
                curr=curr->right;
            }else{
                curr->right=new node(val);
                break;
            }
        }else{
            if(curr->left!=NULL){
                curr->left=curr->left;
            }else{
                curr->left=new node(val);
                break;
            }
        }
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
       
    }
    return 0;
}