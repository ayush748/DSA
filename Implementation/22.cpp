#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    string table;
    vector<string>hand(5);
    cin>>table;
    for(int i=0;i<5;i++){
        cin>>hand[i];
    }
    bool flag=false;
    for(int i=0;i<5;i++){
        if(hand[i][0]==table[0] || hand[i][1]==table[1]){
            flag=true;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}