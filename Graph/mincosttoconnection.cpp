// #include<iostream>
// #include<vector>
// #include<queue>
// #include<functional>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<vector<int>> arr;

//     for(int i=0;i<n;i++){
//         int x,y;
//         cin>>x>>y;
//         arr.push_back({x,y});
//     }

//     vector<vector<pair<int,int>>> adj(n);

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){

//             int x1=arr[i][0];
//             int y1=arr[i][1];

//             int x2=arr[j][0];
//             int y2=arr[j][1];

//             int d=abs(x1-x2)+abs(y1-y2);

//             adj[i].push_back({j,d});
//             adj[j].push_back({i,d});
//         }
//     }

//     priority_queue<
//         pair<int,int>,
//         vector<pair<int,int>>,
//         greater<pair<int,int>>
//     > pq;

//     vector<bool> inMst(n,false);

//     pq.push({0,0});

//     int sum=0;

//     while(!pq.empty()){

//         auto it=pq.top();
//         pq.pop();

//         int wt=it.first;
//         int node=it.second;

//         if(inMst[node])
//             continue;

//         inMst[node]=true;
//         sum+=wt;

//         for(auto nbr:adj[node]){
//             int nb=nbr.first;
//             int nw=nbr.second;

//             if(!inMst[nb]){
//                 pq.push({nw,nb});
//             }
//         }
//     }

//     cout<<sum<<endl;
// }
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        arr.push_back({u,v});
    }
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x1=arr[i][0];
            int x2=arr[i][1];

            int y1=arr[j][0];
            int y2=arr[j][0];

            int d=abs(x1-x2)+abs(y1-y2);
            adj[i].push_back({j,d});
            adj[j].push_back({i,d});
        }
    }
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    >pq;
    vector<int>isMst(n,false);
    vector<int>parent(n,-1);
    int sum=0;
    pq.push({0,0});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int wt=it.first;
        int node=it.second;
        if(isMst[node]){
            continue;
        }
        sum=sum+wt;
        isMst[node]=true;
        for(auto nbr:adj[node]){
            int nb=nbr.first;
            int nw=nbr.second;
            if(!isMst[nb]){
                pq.push({nw,nb});
            }
        }
    }
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>>arr(n);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int u,v;
//             cin>>u>>v;
//             arr.push_back({u,v});
//         }
//     }
//     vector<vector<pair<int,int>>>adj(n);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int x1=arr[i][0];
//             int x2=arr[i][1];

//             int y1=arr[j][0];
//             int y2=arr[j][1];

//             int d=abs(x1-x2)+abs(y1-y2);
//             adj[i].push_back({j,d});
//             adj[j].push_back({i,d});

//         }
//     }
//     priority_queue<
//         pair<int,int>,
//         vector<pair<int,int>>,
//         greater<pair<int,int>>
//     >pq;
//     vector<bool>isMst(n,false);
//     vector<int>parent(n,-1);
//     pq.push({0,0});
//     int sum=0;
//     while(!pq.empty()){
//         auto it=pq.top();
//         pq.pop();
//         int wt=it.first;
//         int node=it.second;
//         if(isMst[node]){
//             continue;
//         }
//         isMst[node]=true;
//         sum=sum+wt;

//     }
//     return 0;
// }