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
    }else if(data>root->data){
        root->right=insertion(root->right,data);
    }
    return root;
}
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root == NULL)
//             return NULL;

//         if(root->val == key)
//             return helper(root);

//         TreeNode* ans = root;

//         while(root != NULL){
//             if(key < root->val){
//                 if(root->left != NULL && root->left->val == key){
//                     root->left = helper(root->left);
//                     break;
//                 }
//                 root = root->left;
//             }
//             else{
//                 if(root->right != NULL && root->right->val == key){
//                     root->right = helper(root->right);
//                     break;
//                 }
//                 root = root->right;
//             }
//         }

//         return ans;
//     }

//     TreeNode* helper(TreeNode* root){
//         if(root->left == NULL)
//             return root->right;

//         if(root->right == NULL)
//             return root->left;

//         TreeNode* rightChild = root->right;
//         TreeNode* last = lastChild(root->left);

//         last->right = rightChild;

//         return root->left;
//     }

//     TreeNode* lastChild(TreeNode* root){
//         while(root->right != NULL){
//             root = root->right;
//         }
//         return root;
//     }
// };
int main(){
    return 0;
}