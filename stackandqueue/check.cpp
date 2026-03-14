#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string text="ababcabcabababd";
    string sub="ababd";
    int pos=text.find(sub);
    if(text.find(sub)!=string::npos){
        cout<<pos<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}