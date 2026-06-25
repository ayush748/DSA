#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=NULL;
        this->right=NULL;
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
}
int diameter(node* root,int maxi){
    if(root==NULL){
        return 0;
    }
    int left=diameter(root->left,maxi);
    int right=diameter(root->right,maxi);
    maxi=max(maxi,left+right);
    return max(left,right)+1;
}
int main(){
    int n;
    cin>>n;
    node* root=NULL;
    int maxi=INT_MIN;

    while(n--){
        root=createTree();
    }
    cout<<diameter(root,maxi);

    return 0;
}
