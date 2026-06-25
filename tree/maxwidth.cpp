#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};
int widthofBinaryTree(node* root){
    if(root==NULL){
        return 0;
    }
    long long ans=0;
    queue<pair<node*,long long>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        long long mini=q.front().second;
        long long first,last;
        for(int i=0;i<size;i++){
            long long cur_id=q.front().second-mini;
            node* curr=q.front().first;
            q.pop();
            if(i==0){
                first=cur_id;
            }
            if(i==size-1){
                last=cur_id;
            }
            if(curr->left){
                q.push({curr->left,2*cur_id+1});
            }

            if(curr->right){
                q.push({curr->right,2*cur_id+2});
            }
        }

        ans=max(ans,last-first+1);
    }
    return (int)ans;
}
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*>mp;
    node* root=NULL;
    while(n--){
        int c,p;
        cin>>c>>p;
        if(mp.find(c)!=mp.end()){
            mp[c]=new node(c);
        }
        if(p==-1){
            root=mp[c];
            continue;
        }
        if(mp.find(p)==mp.end()){
            mp[p]=new node(p);
        }
        node* parent=mp[p];
        node* child=mp[c];
        if(parent->left==NULL){
            parent->left=child;
        }else{
            parent->right=child;
        }

    }
    return 0;
}