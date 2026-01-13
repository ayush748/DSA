// #include<iostream>
// #include<vector>
// #include<list>
// #include<unordered_map>
// using namespace std;
// class Graph{
//     public:
//     unordered_map<int,list<pair<int,int>>>adjList;
//     void addEdge(int u,int v,int wt,int direction){
//         if(direction){
//             adjList[u].push_back({v,wt});
//         }else{
//             adjList[u].push_back({v,wt});
//             adjList[v].push_back({u,wt});
//         }
//     }
//     void printAdjList(){
//         for(auto i:adjList){
//             cout<<i.first<<" ";
//             for(auto j:i.second){
//                 cout<<j.first<<"->"<<j.second;
//             }
//             cout<<endl;
//         }
//     }
// };
// int main(){

//     return 0;
// }


#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;
    void addEdge(int u,int v,int wt,int direction){
        if(direction){
            adjList[u].push_back({v,wt});
        }else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }
    void printadjList(){
        for(auto i:adjList){
            cout<<i.first<<" ";
            for(auto j:i.second){
                cout<<j.first<<"->"<<j.second;
            }
        }
    }
};
int main(){
    Graph g;
    int n;
    for(int i=0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt,1);
    }
    return 0;
}