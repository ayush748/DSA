// #include<iostream>
// #include<vector>
// using namespace std;
// class node{
//     public:
//     int data;
//     node* left;
//     node* right;
//     node(int data){
//         this->data=data;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// node* createTree(){
//     int data;
//     cin>>data;
//     if(data==-1){
//         return NULL;
//     }
//     node* root=new node(data);
//     root->left=createTree();
//     root->right=createTree();
//     return root;
// }
// int maxdepth(node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int left=maxdepth(root->left);
//     int right=maxdepth(root->right);
//     int ans=1+max(left,right);
//     return ans;
// }
// int main(){
//     node* root=createTree();
    
//     cout<<maxdepth(root);

//     return 0;
// }

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
int main(){
    int n;
    cin>>n;
    unordered_map<int,node*>mp;
    node* root=NULL;
    for(int i=0;i<n;i++){
        int c,p;
        cin>>c>>p;
        if(mp.find(c)==mp.end()){
            mp[c]=new node(c);
        }
        if(p==-1){
            root=mp[c];
        }else{
            if(mp.find(p)==mp.end()){
                mp[p]=new node(p);
            }
            node* pa=mp[p];
            if(pa->left==NULL){
                pa->left=mp[c];
            }else{
                pa->left=mp[c];
            }
        }
    }  
    return 0;
}