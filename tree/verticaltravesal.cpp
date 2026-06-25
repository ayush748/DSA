#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>
#include<set>
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

vector<vector<int>> verticalTraversal(node* root){
    vector<vector<int>> ans;

    if(root==NULL){
        return ans;
    }

    map<int,map<int,multiset<int>>> mp;

    queue<pair<node*,pair<int,int>>> q;
    q.push({root,{0,0}});

    while(!q.empty()){
        auto p=q.front();
        q.pop();

        node* n=p.first;
        int x=p.second.first;
        int y=p.second.second;

        mp[x][y].insert(n->data);

        if(n->left){
            q.push({n->left,{x-1,y+1}});
        }

        if(n->right){
            q.push({n->right,{x+1,y+1}});
        }
    }

    for(auto p:mp){
        vector<int> col;

        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }

        ans.push_back(col);
    }

    return ans;
}

int main(){
    return 0;
}