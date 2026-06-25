#include<iostream>
#include<vector>
using namespace std;
void print(int *p){
    cout<<*p<<endl;
    *p=*p+1;
}
void update(int *p){

    p=p+1;
    cout<<*p<<endl;
}
void solve(int arr[],int n){

}
void solve(int *arr,int n){
    
}
int main(){
    // int val=5;
    // int *p=&val;
    // update(p);
    // cout<<val;

    int arr[5]={1,2,3,4,5};
    solve(arr,5);
    return 0;
}