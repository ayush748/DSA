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
node* insertion(node* root ,int data){
    if(root==NULL){
        node* newnode=new node(data);
        return newnode;
    }
    if(data > root->data){
        root->left=insertion(root->left,data);
    }else{
        root->right=insertion(root->right,data);
    }
    return root;
}
bool solve(node* root,long long int lb,long long int ub){
    if(root==NULL){
        return true;
    }
    bool cond1=root->data>lb;
    bool cond2=root->data<ub;
    bool lans=solve(root->left,lb,root->data);
    bool rans=solve(root->right,root->data,ub);
    if(cond1 && cond2 && lans && rans){
        return true;
    }else{
        return false;
    }
}
bool isValidBst(node* root,int &k){
    long long int lb=LONG_MIN;
    long long int ub=LONG_MAX;
    bool ans=solve(root,lb,ub);
    return ans;
}
int main(){
    return 0;
}