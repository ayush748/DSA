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
        newnode=root;
    }
    if(root->data>data){
        root->left=btree(root->left,data);
    }else if(root->data<data){
        root->right=btree(root->right,data);
    }
    return root;
}
// vector<int> inorder(node* &r){
//     vector<int>ans;
//     if(r==NULL){
//         return ans;
//     }
//     node* root=r;
//     stack<node*>st;
//     st.push(root);
//     while(true){
//         if(root!=NULL){
//             st.push(root);
//             root=root->left;
//         }else{
//             if(st.empty()){
//                 break;
//             }
//             root=st.top();
//             st.pop();
//             ans.push_back(root->data);
//             root=root->right;
//         }
//     }
//     return ans;
    
// }

vector<int>inorder(node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    node* r=root;
    stack<node*>st;
    st.push(r);
    while(true ){
        if(r!=NULL){
            st.push(r);
            r=r->left;
        }else{
            if(st.empty()){
                break;
            }
            r=st.top();
            st.pop();
            ans.push_back(r->data);
            r=r->right;
        }
    }
    return ans;
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
        btree(root,arr[i]);
    }
    return 0;
}