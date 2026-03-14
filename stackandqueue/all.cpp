#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string text="ababcabcabababd";
    string sub="ab";
    int pos=text.find(sub);
    while(pos!=string::npos){
        cout<<pos<<" ";
        pos=text.find(sub,pos+1);
    }
    return 0;
}