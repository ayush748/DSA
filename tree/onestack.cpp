#include<iostream>
#include<vector>
#include<stack>
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
// void postorder(node* root){
//     stack<node*>st;
//     node* curr=root;
//     node* last=NULL;
//     while(curr || st.empty()){
//         if(curr){
//             st.push(curr);
//             curr=curr->left;
//         }else{
//             node* temp=st.top();
//             if(temp->right && last!=temp->right){
//                 curr=temp->right;
//             }else{
//                 cout<<temp->data<<" ";
//                 last=temp;
//                 st.pop();
//             }
//         }
//     }

// }

// void postorder(node* root){
//     stack<node*>st;
//     node* curr=root;
//     node* last=NULL;
    
//     while(curr || st.empty()){
//         if(curr){
//             st.push(curr);
//             curr=curr->left;
//         }else{
//             node* temp=st.top();
//             if(temp->right && last!=temp->right){
//                 curr=temp->right;
//             }else{
//                 cout<<temp->data<<" ";
//                 last=temp;
//                 st.pop();
//             }
//         }
//     }
// }

// void postorder(node* root){
//     stack<node*>st;
//     node* curr=root;
//     node* last=NULL;
//     while(curr || st.empty()){
//         if(curr){
//             st.push(curr);
//         }else{
//             node* temp=st.top();
//             if(temp->right && last!=temp->right){
//                 curr=temp->right;
//             }else{
//                 cout<<temp->data;
//                 last=temp;
//                 st.top();
//             }
//         }
//     }
// }

void postorder(node* root){
    stack<node*>st;
    node* curr=root;
    node* last=NULL;
    while(curr || !st.empty()){
        if(curr){
            st.push(curr);
            curr=curr->left;
        }else{
            node* temp=st.top();
            if(temp->right && last!=temp->right){
                curr=temp->right;
            }else{
                cout<<temp->data;
                last=temp;
                st.pop();
            }
        }
    }
}
void preInPost(node* root){
    stack<pair<node*,int>>st;
    st.push({root,1});
    vector<int>pre,in,post;
    if(root==NULL){
        return ;
    }
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }else{
            post.push_back({it.first->right,1)};
        }
    }
}
int main(){
    return 0;
}