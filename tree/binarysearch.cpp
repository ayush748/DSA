#include<iostream>
#include<vector>
#include<queue>
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
node* createTree(node* root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        return newnode;
    }
    if(data<root->data){
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
    return 0;
}