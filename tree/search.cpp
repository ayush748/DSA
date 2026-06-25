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
        this->right=NULL;
    }
};
node* insertion(node* root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=insertion(root->left,data);
    }else if(data>root->data){
        root->right=insertion(root->right,data);
    }
    return root;   
}
bool searchTree(node* root,int data){
    while(root!=NULL){
        if(root->data==data){
            return true; 
        }
        if(data<root->data){
            root=root->left;
        }else{
            root=root->right;
        }
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
    
    return 0;
}