#include<iostream>
#include<vector>
using namespace std;
int main(){
    // int arr[10];
    // cout<<arr;
    cout<<endl;

    // vector<int>brr(10);
    // cout<<&brr[0];
    // cout<<&arr[0];
    // int arr[10]={2,5,6};
    // cout<<arr[0]<<endl;
    // cout<<*arr;
    // cout<<endl;
    // cout<<*arr+1<<endl;
    // cout<<"2nd "<<*(arr+1)<<endl;
    // cout<<"1st "<<(*arr)+1<<endl;
    // cout<<"3th "<<*(arr+2)<<endl;
    // int i=0;
    // cout<<i[arr]<<" "<<*(i+arr)<<endl;
    // i=2;
    // cout<<i[arr]<<endl;
    // int *p=&arr[0];
    // cout<<endl;
    // cout<<*p<<endl;
    // int *q=(arr+0);
    // cout<<*q;
    // *q=i[arr];
    // cout<<endl;
    // cout<<*q;
    // i = 1;
    // int *a = (arr + i);
    // int  temp[10];
    // cout<<sizeof(temp);
    // int *ptr=temp;
    // cout<<endl;
    // cout<<sizeof(ptr)<<endl;
    // cout<<sizeof(*ptr)<<endl;
    // cout<<sizeof(&ptr)<<endl;
    // cout<<"2nd"<<sizeof(&temp);
    int a[20]={1,2,3,4,5};
    cout<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;
    int *p=&a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    p=p+1;
    cout<<*p;
    return 0;
}