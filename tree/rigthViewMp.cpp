#include<iostream>
#include<vector>
#include<unordered_map>
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
void rightView(node* root,int level,vector<int>arr){
    if(root==NULL){
        return ;
    }
    if(arr.size()==level){
        arr.push_back(root->data);
    }
    rightView(root->left,level+1,arr);
    rightView(root->right,level+1,arr);
}
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*>mp;
    node* root=NULL;
    while(n--){
        int child,parent;
        cin>>child>>parent;
        if(mp.find(child)==mp.end()){
            mp[child]=new node(child);
        }
        if(parent==-1){
            root=mp[child];
            continue;
        }
        if(mp.find(parent)==mp.end()){
            mp[parent]=new node(parent);
        }
        node* p=mp[parent];
        node* c=mp[child];
        if(p->left==NULL){
            p->left=c;
        }else{
            p->right=c;
        }

    }
    return 0;
}