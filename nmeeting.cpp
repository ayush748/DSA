// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<tuple>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);//staart
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int>brr(n);//end
//     for(int i=0;i<n;i++){
//         cin>>brr[i];
//     }
//     vector<tuple<int,int,int>>meeting;
//     for(int i=0;i<n;i++){
//         meeting.push_back({brr[i],arr[i],i+1});
//     }
//     sort(meeting.begin(),meeting.end());
//     vector<int>res;
//     int las=-1;
//     for(int i=0;i<n;i++){
//         int e=get<0>(meeting[i]);
//         int s=get<1>(meeting[i]);
//         int idx=get<2>(meeting[i]);
//         if(s>=las){
//             res.push_back(idx);
//             las=e;
//         }

//     }
//     for(int i=0;i<res.size();i++){
//         cout<<res[i]<<" ";
//     }
//     return 0;
// }

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>start(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    vector<int>end(n);
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    vector<tuple<int,int,int>>meeting;
    for(int i=0;i<n;i++){
        meeting.push_back({end[i],start[i],i+1});
    }
    sort(meeting.begin(),meeting.end());
    int lastidx=-1;
    vector<int>res;
    for(int i=0;i<n;i++){
        int e=get<0>(meeting[i]);
        int s=get<1>(meeting[i]);
        int idx=get<2>(meeting[i]);
        if(s>=lastidx){
            lastidx=e;
            res.push_back(idx);
        }
    }
    
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}