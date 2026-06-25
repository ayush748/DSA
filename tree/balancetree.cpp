// #include<iostream>
// #include<vector>
// using namespace std;
// class node{
//     public:
//     int data;
//     node* left;
//     node* right;
//     node(int data){
//         this->data=data;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// node* createTree(){
//     int data;
//     cin>>data;
//     if(data==-1){
//         return NULL;
//     }
//     node* root=new node(data);
//     root->left=createTree();
//     root->right=createTree();
//     return root;
// }
// int checkbalace(node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int l=checkbalace(root->left);
//     if(l!=-1){
//         return -1
//     }
//     int r=checkbalace(root->right);
// }
// int main(){
//     return 0;
// }