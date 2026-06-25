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
node* lca(node* root,node* p,node* q){
    if(root==NULL){
        return NULL;
    }
    int curr=root->data;
    if(curr<p->data && curr<q->data){
        return lca(root->right,p,q);
    }
    if(curr>p->data && curr>q->data){
        return lca(root->left,p,q);
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