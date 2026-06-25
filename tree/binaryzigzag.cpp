#include<iostream>
#include<vector>
#include<queue>
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
node* createtree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* root=new node(data);
    root->left=createtree();
    root->right=createtree();
    return root;
}
vector<vector<int>>zigzag(node* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    bool flag=true;
    while(!q.empty()){
        int n=q.size();
        vector<int>row(n);
        for(int i=0;i<n;i++){
            auto front=q.front();
            q.pop();
            int index=flag?i:n-i-1;
            row[index]=front->data;
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
        ans.push_back(row);
        flag=!flag;
    }
}
int main(){
    int n;
    cin>>n;
    node* root=NULL;
    for(int i=0;i<n;i++){
        createtree();
    }
    return 0;
}