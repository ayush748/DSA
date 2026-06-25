#include<iostream>
#include<vector>
#include<algorithm>
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
node* insertion(node* root,int data){
    if(root==NULL){
        node* newnode=new node(data);
        return root;
    }
    if(data<root->data){
        root->left=insertion(root->left,data);
    }else{
        root->right=insertion(root->right,data);
    }
    return root;
}
void solve(node* root,vector<int>&arr){

    if(root==NULL){
        return ;
    }
    solve(root->left,arr);
    arr.push_back(root->data);
    solve(root->right,arr);
}
// void solvem2(node* root,int ub,int key){
//     if(root==NULL){
//         return ;
//     }

//     solvem2(root->left,ub,key);
//     if(ub>key && root->data<ub){
//         ub=root->data;
//     }
//     solvem2(root->right,ub,key);

// }

void solvem2(node* root,int ub,int key){
    if(root==NULL){
        return ;
    }
    solvem2(root->left,ub,key);
    if(root->data >key && root->data < ub){
        ub=root->data;
    }
    solvem2(root->right,ub,key);
}
node* inoder(node* root,node* p){
    node* s=NULL;
    while(root!=NULL){
        if(p->data >=root->data){
            root=root->right;
        }else{
            s=root;
            root=root->left;
            
        }
    }
    return s;
}
int preordersolve(node* root,node* p){
    
    vector<int>arr;
    solvem2(root,INT_MAX,8);

    int ub=INT_MAX;
    solvem2(root,ub,p->data);
    if(ub==INT_MAX){
        return -1;
    }
    return ub;

    // int s=0;
    // int n=arr.size();
    // int e=n-1;
    // int mid=s+(e-s)/2;
    // int ans=-1;
    // int val=p->data;
    // while(s<=e){
    //     if(arr[mid]>val){
    //         ans=arr[mid];
    //         e=mid-1;
    //     }else{
    //         s=mid+1;
    //     }
    //     mid=s+(e-s)/2;
    // }


}
int main(){
    return 0;
}