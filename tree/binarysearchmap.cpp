#include<iostream>
#include<vector>
#include<algorithm>
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
node* insertionTree(node* root,int val){
    if(root==NULL){
        node* newnode=new node(val);
        return newnode;
    }
    if(val<root->data){
        root->left=insertionTree(root->left,val);
    }else{
        root->right=insertionTree(root->right,val);
    }
    return root;
}
bool searchTree(node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(target<root->data){
        return searchTree(root->left,target);
    }else{
        return searchTree(root->right,target);
    }
    return false;
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
        root=insertionTree(root,arr[i]);
    }
    bool ans=searchTree(root,5);
    return 0;
}