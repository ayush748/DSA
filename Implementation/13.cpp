// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     bool flag=true;
    
//     while(n>0){
//         int ans=n%10;
//         // cout<<ans;
//         if(ans!=4 && ans!=7){
//             flag=false;
//             break;
//         }
//         n=n/10;
//     }
//     if(flag){
//         cout<<"Yes";
//     }else{
//         cout<<"No";
//     }
//     return 0;
// }
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    while(n>0){
        int val=n%10;
        mp[val]++;
        n=n/10;
    }
    bool flag=false;
    for(auto it=mp.begin();it!=mp.end();it++){
        int val1=it->first;
        if(val1!=4 || val1!=7){
            flag=true;
        }
    }
    if(flag){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return  0;
}