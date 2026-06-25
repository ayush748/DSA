#include<iostream>
#include<vector>
using namespace std;
int main(){
    // int n=5;
    // cout<<n;
    // int *ptr=&n;
    // cout<<*ptr;
    // n++;
    // cout<<endl;
    // cout<<*ptr;
    // cout<<ptr<<endl;

    // double d=4.3;
    // double *p2=&d;
    // cout<<p2;
    // cout<<*p2;
    // cout<<endl;
    // cout<<sizeof(p2);
    // cout<<endl;
    // cout<<sizeof(n);
    // int n=5;
    // int *p=0;
    // p=&n;
    // cout<<*p;

    // int n=5;
    // int *ptr=&n;
    // int a=*ptr;
    // a++;
    // cout<<n;

    // (*ptr)++;
    // cout<<n;
    // return 0;

    // int num=5;
    // int a=num;
    // cout<<"a before"<<num<<endl;
    // a++;
    // cout<<"b before"<<num<<endl;

    // int *p=&num;
    // cout<<"before"<<num<<endl;
    // (*p)++;
    // cout<<"after"<<num<<endl;
    // int *q=p;
    // cout<<p<<"-"<<q<<endl;
    // cout<<*p<<"-"<<*q<<endl;

    int i=0;
    int *x=&i;
    // (*x)++;
    // ++(*x)
    *x=*x+12;
    cout<<*x<<endl;
    cout<<&i<<endl;
    cout<<x<<endl;
    x=x+1;
    cout<<x<<endl;

}