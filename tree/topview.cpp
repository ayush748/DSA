#include<iostream>
#include<vector>
#include<queue>
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
node* createTree(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* root=new node(data);
    root->left=createTree();
    root->right=createTree();
    return root;
}
vector<int>topview(node* root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    unordered_map<int,int>mp;
    queue<pair<int,node*>>q;
    q.push({0,root});
    while(!q.empty()){
        auto frontnode=q.front();
        q.pop();
        int vindex=frontnode.first;
        node* root=frontnode.second;

        if(mp.find(vindex)!=mp.end()){
            mp[vindex]=root->data;
        }

        if(root->left!=NULL){
            q.push({vindex-1,root->left});
        }
        if(root->right!=NULL){
            q.push({vindex+1,root->right});

        }
    }

    for(auto nbr:mp){
        ans.push_back(nbr.second);
    }

}
int main(){
    
    node* root=NULL;
    int n;
    cin>>n;
    while(n--){
        createTree();
    }
    
    
    return 0;
}