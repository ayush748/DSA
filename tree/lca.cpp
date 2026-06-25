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
        this->right=NULL;
        this->left=NULL;
    }
};
node* solve(node* root,node* p,node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    node* left=solve(root->left,p,q);
    node* right=solve(root->right,p,q);
    if(left==NULL){
        return right;
    } 
    else if(right==NULL){
        return left;
    }else{
        return root;
    }

}
int main(){
    int n;
    cin>>n;
    node* root=NULL;
    unordered_map<int,node*>mp;
    while(n--){
        int p,c;
        cin>>p>>c;
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
        node* pa=mp[p];
        node* ch=mp[c];
        if(pa->left==NULL){
            pa->left=ch;
        }else{
            pa->right=ch;
        }
    }

    
    return 0;
}