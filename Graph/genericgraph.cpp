// #include<iostream>
// #include<list>
// #include<unordered_map>
// #include<vector>
// using namespace std;
// template<typename T>
// class Graph{
//     public:
//     unordered_map<T,list<pair{T,int}>>adjList;
//     void addEdge(T u,T v ,int wt,bool direction){
//         if(direction){
//             adjList[u].push_back({v,wt});
//         }else{
//             adjList[u].push_back({v,wt});
//             adjList[v].push_back({u,wt});
//         }
//     }
//     void printAdjList(){
//         for(auto i:adjList){
//             cout<<i.first;
//             for(pair<T,int>nbr:i.second){
//                 cout<<nbr.first<<"->"<<nbr.second;
//             }
//             cout<<endl;
//         }
//     } 
// };
// int main(){
//     Graph<int> g;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int u,v,wt;
//         cin>>u>>v>>wt;
//         g.addEdge(u,v,wt,1);
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
int main(){
    return 0;
}