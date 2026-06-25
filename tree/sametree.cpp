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
bool solve(node* p,node* q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL && q==NULL){
        return false;
    }
    int data1=p->data;
    int data2=q->data;
    int l=solve(p->left,q->left);
    int r=solve(p->right,q->right);
    return l && r;
}
bool isSameTree(node* p,node* q){
    bool ans=solve(p,q);
    return ans;
}
int main(){
    int n;
    cin>>n;
    node* root1=NULL;
    for(int i=0;i<n;i++){
        root1=createTree();
    }
    node* root2=NULL;
    for(int i=0;i<n;i++){
        root2=createTree();
    }
    bool ans=isSameTree(root1,root2);
    if(ans){
        cout<<true;
    }else{
        cout<<true;
    }
    return 0;

}