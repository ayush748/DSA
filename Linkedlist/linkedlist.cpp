#include<iostream>
#include<vector>
#include<unordered_map>
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
    if(head!=NULL){
        head=newnode;
    }
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
    }
    temp=temp->next;
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
    while(i<arr.size()){
        insertionTail(head,arr[i]);
        i++;
    }
    node* temp=head;
    bool flag=false;
    unordered_map<node*,bool>mp;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            flag=true;
            break;
        }else{
            mp[temp]=true;
        }
        temp=temp->next;
    }
    
    
    return 0;
}