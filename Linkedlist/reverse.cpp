#include<iostream>
#include<vector>
#include<algorithm>
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
int len(node* head){
    node* temp=head;
    int len=0;

    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
node* reverse(node* head){
    node* pre=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* temp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=temp;
    }
    return pre;
}
void insertion(node* &head,int d){
    node* newnode=new node(d);
    if(head==NULL){
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void print(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int n;
    cin>>n;
    node* head=NULL;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertion(head,x);

    }
    head=reverse(head);
    return 0;
}