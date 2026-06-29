#include<iostream>
#include<vector>
#include<queue>
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
auto lambda=[](node* n1,node* n2){
    return n1->data > n2->data;
};
node* mergesortedlist(vector<node*>&arr){
    priority_queue<node*,vector<node*>,decltype(lambda)>pq(lambda);
    for(node* n:arr){
        if(n!=NULL){
            pq.push(n);
        }
    }
    if(pq.empty()){
        return NULL;
    }
    node* h=pq.top();
    pq.pop();
    if(h->next!=NULL){
        pq.push(h->next);
    }
    node* t=h;
    while(!pq.empty()){
        node* curr=pq.top();
        pq.pop();
        t->next=curr;
        t=t->next;
        if(curr->next!=NULL){
            pq.push(curr->next);
        }
    }
    return h;
}
int main(){
    
    return 0;
}