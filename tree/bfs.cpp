#include<iostream>
#include<vector>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
vector<vector<int>> bfs(node* root){
    vector<vector<int>>ans;
    if(root==NULL){
        return ans;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for(int i=0;i<size;i++){
            node* frontnode=q.front();
            q.pop();
            if(!frontnode->left){
                q.push(frontnode->left);
            }
            if(!frontnode->right){
                q.push(frontnode->right);
            }

            level.push_back(frontnode->data);
        }
        ans.push_back(level);
    }
    return ans;
}
int main(){

    return 0;
}