#include<iostream>
#include<vector>
#include<stack>
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
node* btree(node* root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        root=newnode;
        return root;
    }
    if(root->data>data){
        root->left=btree(root->left,data);
    }else{
        root->right=btree(root->right,data);
    }
    return root;
}
void iterativepre(node* &root,vector<int>&ans){
    if(root=NULL){
        cout<<-1;
        return ;
    }
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node* front=st.top();
        st.pop();
        ans.push_back(front->data);
        if(front->right!=NULL){
            st.push(front->right);
        }
        if(front->left!=NULL){
            st.push(front->left);
        }
    }
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
        root=btree(root,arr[i]);
    }
    vector<int>ans;
    node* root=NULL;
    iterativepre(root,ans);
    return 0;
}