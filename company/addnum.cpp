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
node* build(vector<int>&arr){
    node* head=NULL;
    node* tail=NULL;

    for(int i=0;i<arr.size();i++){
        node* temp=new node(arr[i]);
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}
node* rev(node* head){
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
node* addtwonumber(node* l1,node* l2){
    l1=rev(l1);
    l2=rev(l2);
    int carry=0;
    node* h1=l1;
    node* h2=l2;
    node* newnode=new node(0);
    node* head=newnode;
    while(h1!=NULL || h2!=NULL || carry){
        int val1=carry;
        if(h1!=NULL){
            val1=val1+h1->data;
        }
        if(h2!=NULL){
            val1=val1+h2->data;
        }
        int v=val1%10;
        carry=val1/10;
        node* temp=new node(v);
        head->next=temp;
        head=temp;
    }
    return rev(newnode->next);
}
int main(){
    int n,m;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    cin>>m;
    vector<int>b(m);
    for(int i=0;i<m;i++) cin>>b[i];

    node* l1=build(a);
    node* l2=build(b);

    node* ans=addtwonumber(l1,l2);
    // print(ans);

    return 0;

    return 0;
}