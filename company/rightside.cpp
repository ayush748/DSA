#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class node{
    public:
    int data;
    node* right;
    node* left;
    node* next;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
        this->next=NULL;
    }
};
node* lowestCommonAncestor(node* root,node* p,node* q){
    if(root==NULL || p==root || q==root){
        return root;
    }
    node* left=lowestCommonAncestor(root->left,p,q);
    node* right=lowestCommonAncestor(root->right,p,q);
    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }else{
        return root;
    }
}
vector<int>solve(node* root){
    vector<int>arr;
    if(root==NULL){
        return arr;
    }
    queue<pair<node*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        node* val=front.first;
        int hd=front.second;
        mp[hd]=val->data;
        if(val->left!=NULL){
            q.push({val->left,hd-1});
        }
        if(val->right!=NULL){
            q.push({val->right,hd+1});
        }
    }
    int data=mp.begin()
    for(auto it:mp){
        arr.push_back(it.second);
    }
    return arr;
}
void dfs(node* root,int level,vector<int>&arr){
    if(root==NULL){
        return ;
    }
    if(level==arr.size()){
        arr.push_back(root->data);
    }
    dfs(root->right,level+1,arr);
    dfs(root->left,level+1,arr);
}
node* root(node* root){
    if(root==NULL){
        return NULL;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        node* prev=NULL;
        for(int i=0;i<n;i++){
            node* front=q.front();
            q.pop();
            if(prev!=NULL){
                prev->next=front;
            }
            prev=front;
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}
vector<int>rightside(node* root){
    vector<int>arr;
    if(root==NULL){
        return arr;
    }
    queue<node*>q;
    q.push(root);
    while(!q.size()){
        int n=q.size();
        for(int i=0;i<n;i++){
            auto front=q.front();
            q.pop();
            if(i==n-1){
                arr.push_back(front->data);
            }
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
    return arr;

}
int main(){

    return 0;
}