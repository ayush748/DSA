#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>greed={1,2,3};
    vector<int>s={1,1};
    int n=greed.size();
    int m=s.size();
    int i=0;
    int j=0;
    int cnt=0;
    while(j<n){
        if(greed[i]<=s[j]){
            i++;
            cnt;
        }
        j++;
    }
    cout<<cnt;
    return 0;
}