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
void insertiontail(node* head,int data){
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
node* reversell(node* head){
    node* pre=NULL;
    node* curr=head;

    while(curr!=NULL){
        node* temp=curr->next;
        curr->next;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    
    return 0;
}