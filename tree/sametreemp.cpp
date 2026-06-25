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
bool solve(node* p,node* q){
    if(p==NULL && q==NULL){
        return true;
    }
    if(p==NULL || q==NULL){
        return false;
    }
    int val1=p->data;
    int val2=q->data;
    if(val1!=val2){
        return false;
    }
    bool l=solve(p->left,q->left);
    bool r=solve(p->right,q->right);
    return l && r;
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
            root=mp[parent];
            continue;
        }
        if(mp.find(parent)!=mp.end()){
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
    unordered_map<int,node*>mp2;
    node* root2=NULL;
    for(int i=0;i<n;i++){
        int child,parent;
        cin>>child>>parent;
        if(mp2.find(child)!=mp2.end()){
            mp2[child]=new node(child);
        }
        if(parent==-1){
            root2=mp2[parent];
            continue;
        }
        if(mp2.find(parent)!=mp2.end()){
            mp2[parent]=new node(parent);
        }
        node* p=mp2[parent];
        node* c=mp2[child];
        if(p->left==NULL){
            p->left=c;
        }else{
            p->right=c;
        }
    }

    cout<<solve(root,root2);
    
    return 0;
}