#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>bills(n);
    for(int i=0;i<n;i++){
        cin>>bills[i];
    }
    int one=0;
    int two=0;

    for(int i=0;i<n;i++){
        if(bills[i]==5){
            one++;
        }else if(bills[i]==10){
            if(one>0){
                one--;
                two++;
            }else{
                return false;
            }
        }else{
            if(one>0 && two>0){
                one--;
                two--;
            }else if(one>=3){
                one=one-3;
            }else{
                return false;
            }
        }
    }
    return 0;
}