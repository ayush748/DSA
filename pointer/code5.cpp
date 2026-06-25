#include<iostream>
#include<vector>
using namespace std;
void updatte(int **p){
    p=p+1;
    
    *p=*p+1;

    **p=**p+1;
}
int main(){
    int i=5;
    int *ptr=&i;
    int **ptr2=&ptr;

    cout<<i<<endl;
    cout<<*ptr<<endl;
    cout<<**ptr2<<endl; 

    cout<<endl;
    cout<<&i<<endl;
    cout<<&ptr<<endl;
    cout<<&ptr2<<endl;
    cout<<endl;
    cout<<ptr<<endl;
    cout<<*ptr2<<endl;
    cout<<endl;
    cout<<&*ptr2<<endl;
    return 0;
}