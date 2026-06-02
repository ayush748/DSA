#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertionTail(node* head,int data){
    node* newnode=new node(data);
    if(head==NULL){
        head=newnode;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    
}
void solve(node* head,vector<int>&arr){
    node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    node* head=NULL;
    while(i<n){
        insertionTail(head,arr[i]);
        i++;
    }
    vector<int>ans;
    node * newnode=new node(NULL);
    node* temp=newnode;
    solve(head,ans);
    int i=0;
    int e=n-1;
    while(i<=e){
        if(i!=e){
            node* f=new node(arr[i]);
            temp->next=f;
            temp=f;
            node* en=new node(arr[e]);
            temp->next=en;
            temp=en;
        }else{
            node* f=new node(arr[i]);
            temp->next=f;
            temp=f;
        }
        i++;
        e--;
    }
    return 0;
}