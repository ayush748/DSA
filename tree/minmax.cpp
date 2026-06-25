// #include<iostream>
// using namespace std;
// class node{
// public:
//     int data;
//     node* left;
//     node* right;

//     node(int data){
//         this->data=data;
//         left=NULL;
//         right=NULL;
//     }
// };

// node* insertion(node* root,int data){
//     if(root==NULL){
//         return new node(data);
//     }

//     if(data<root->data){
//         root->left=insertion(root->left,data);
//     }
//     else{
//         root->right=insertion(root->right,data);
//     }

//     return root;
// }

// int minTree(node* root){
//     if(root==NULL) return -1;

//     while(root->left!=NULL){
//         root=root->left;
//     }

//     return root->data;
// }

// int maxTree(node* root){
//     if(root==NULL) return -1;

//     while(root->right!=NULL){
//         root=root->right;
//     }

//     return root->data;
// }

// int main(){
//     node* root=NULL;

//     root=insertion(root,10);
//     root=insertion(root,5);
//     root=insertion(root,15);
//     root=insertion(root,2);
//     root=insertion(root,20);

//     cout<<"Min = "<<minTree(root)<<endl;
//     cout<<"Max = "<<maxTree(root)<<endl;

//     return 0;
// }

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
        node* newnode=new node(data);
        return newnode;
    }

    if(data<root->data){
        root->left=insertion(root->left,data);
    }else{
        root->right=insertion(root->right,data);
    }
    return root;
}
int minTree(node* root){
    if(root==NULL){
        return -1;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
int maxTree(node* root){
    if(root==NULL){
        return -1;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
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
        root=insertion(root,arr[i]);
    }
    
    return 0;
}