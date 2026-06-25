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
        this->left=NULL;

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
int pathsum(node* root,int sum){
    if(root==NULL){
        return 0;
    }
    int left=max(0,pathsum(root->left,sum));
    int right=max(0,pathsum(root->right,sum));
    sum=max(sum,root->data+left+right);
    return root->data+max(left,right);
}
int solve(node* root){
    int ans=INT_MIN;
    int val=0;
    int sum=pathsum(root,ans);
    return ans;
}
int main(){
    
    return 0;
}