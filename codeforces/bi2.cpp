#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<string>val={"atiwari","bat","dog","dog","doggy","bat" ,"ayush"};
    sort(val.begin(),val.end());
    int n=val.size();
    for(int i=0;i<n;i++){
        cout<<val[i]<<" ";
    }
    return 0;
}