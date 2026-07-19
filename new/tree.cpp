// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *left, *right;

//     Node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// // Build Tree using Recursion
// Node* buildTree() {
//     int val;
//     cin >> val;

//     if (val == -1)
//         return NULL;

//     Node* root = new Node(val);

//     root->left = buildTree();
//     root->right = buildTree();

//     return root;
// }
// void preorder(Node* root) {
//     if (root == NULL)
//         return;

//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
// void inorder(Node* root) {
//     if (root == NULL)
//         return;

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }
// void postorder(Node* root) {
//     if (root == NULL)
//         return;

//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }

// int main() {
//     cout << "Enter tree in preorder (-1 for NULL):\n";

//     Node* root = buildTree();
//     cout << "\nPreorder: ";
//     preorder(root);
//     cout << "\nInorder: ";
//     inorder(root);
//     cout << "\nPostorder: ";
//     postorder(root);

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
node* buildTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* root=new node(data);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int main(){
    
    return 0;
}