#include<iostream>
#include<vector>
using namespace std;
int main(){
    // char ch[5]="abcde";
    char ch[6]="abcde";
    cout<<ch;
    cout<<endl;
    char *c=&ch[0];
    cout<<*c;
    cout<<endl;
    cout<<c;

    char temp='z';
    char *p=&temp;
    cout<<p<<endl; 
    return 0;
}