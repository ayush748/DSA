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
int floorsearch(node* root,int data){
    int floor=-1;
    while(root!=NULL){
        if(root->data==data){
            floor=root->data;
            return floor;
        }

        if(data>root->data){
            floor=root->data;
            root=root->right;
        }else{
            root=root->left;
        }
    }
    return floor;
}
int main(){
    return 0;
}