#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s;
    string k;
    int pos=s.find(k);
    if(pos==string::npos){
        cout<<-1<<endl;
    }
    cout<<pos;
    return 0;
}