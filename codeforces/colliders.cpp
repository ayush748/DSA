#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    // arr[0]=arr[1]=false;
    // for (int i=2;i*i<=n;i++){
    //     if (arr[i]){
    //         for (int j=i*i;j<=n;j=j+i){
    //             arr[j] = false;
    //         }
    //     }
    // }

    int n,m;
    cin>>n>>m;
    unordered_map<int, vector<int>>mp;
    for(int i=2;i<=n;i++){
        for (int j=i;j<=n;j=j+i){
            mp[j].push_back(i);
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<"->";
        for (auto nbr:it->second){
            cout<<nbr<<" ";
        }
        cout <<endl;
    }


    return 0;
}



