#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class node{
    public:
    int data;
    node* right;
    node* left;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
void reorder(node* root){
    if(root==NULL){
        return;
    }
    int child=0;
    if(root->left){
        child=child+root->left->data;
    }
    if(root->right){
        child=child+root->right->data;
    }
    if(child>=root->data){
        child=child+root->right->data;
    }
    else{
        if(root->left){
            root->left->data=root->data;
        }else if(root->right){
            root->right->data=root->data;
        }
    }
    reorder(root->left);
    reorder(root->right);
    int tot=0;
    if(root->left){
        tot=tot+root->left->data;
    }
    if(root->right){
        tot=tot+root->right->data;
    }
    if(root->left || root->right){
        root->data=tot;
    }

}
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*>mp;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int child,parent;
        cin>>child>>parent;
        if(mp.find(child)!=mp.end()){
            mp[child]=new node(child);
        }
        if(parent==-1){
            mp[parent]=root;

        }
        if(mp.find(parent)!=mp.end()){
            mp[parent]=new node(parent);
        }
        node* p=mp[parent];
        node* c=mp[child];
        if(p->left==NULL){
            p->left=NULL;
        }else{
            p->right=NULL;
        }
    }
    return 0;
}