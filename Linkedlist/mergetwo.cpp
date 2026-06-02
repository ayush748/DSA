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

void insertiontail(node* &head,int data){
    node* newnode=new node(data);

    if(head==NULL){
        head=newnode;
        return;
    }

    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
}

void println(node* head){
    node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr1(n);
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    vector<int> arr2(n);
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    node* head1=NULL;
    for(int i=0;i<n;i++){
        insertiontail(head1,arr1[i]);
    }
    node* head2=NULL;
    for(int i=0;i<n;i++){
        insertiontail(head2,arr2[i]);
    }
    vector<int> arr;
    for(int x:arr1) arr.push_back(x);
    for(int x:arr2) arr.push_back(x);
    sort(arr.begin(),arr.end());
    node* mergedHead=NULL;
    for(int x:arr){
        insertiontail(mergedHead,x);
    }
    println(mergedHead);
    return 0;
}