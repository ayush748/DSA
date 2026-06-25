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
        this->right=NULL;
        this->left=NULL;
    }
};
node* insertion(node* root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        return newnode;
    }

    if(data>root->data){
        root->right=insertion(root->left,data);
    }else{
        root->left=insertion(root->right,data);
    }
    return root;
}
int kthsmallest(node* root,int &k){
    if(root==NULL){
        return -1;
    }
    int leftans=kthsmallest(root->left,k);
    if(leftans!=-1){
        return leftans;
    }
    k--;
    if(k==0){
        return root->data;
    }
    int rightans=kthsmallest(root->right,k);
    return rightans;
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