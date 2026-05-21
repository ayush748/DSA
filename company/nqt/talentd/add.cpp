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
node* create(vector<int>&arr){
    int n=arr.size();
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++){
        node* newnode=new node(arr[i]);
        if(head==NULL && tail==NULL ){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}
node* addnode(node* l1,node* l2){
    node* h1=l1;
    node* h2=l2;
    node* newnode=new node(NULL);
    node* temp=newnode;
    int carry=0;
    while(h1!=NULL || h2!=NULL || carry){
        int val=carry;
        if(h1!=NULL){
            val=val+h1->data;
            h1=h1->next;
        }
        if(h2!=NULL){
            val=val+h2->data;
            h2=h2->next;
        }
        int d=val%10;
        carry=val/10;
        node* digit=new node(d);
        temp->next=digit;
        temp=digit;

    }
    return newnode->next;
}
void printll(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>brr(m);
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    node* l1=create(arr);
    node* l2=create(arr);
    node* ans=addnode(l1,l2);
    printll(ans);
    return 0;
}