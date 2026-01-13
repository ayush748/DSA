#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
// class Graph{
//     public:
//     unordered_map<int,list<int>>adjlist;
//     void addEdge(int u,int v,bool direction){
//         if(direction){
//             adjlist[u].push_back(v);
//         }else{
//             adjlist[v].push_back(u);
//             adjlist[u].push_back(v);
//         }
//     }
//     void printGraph(){
//         for(auto &node:adjlist){
//             cout<<node.first;
//             for(auto &nbr:node.second){
//                 cout<<nbr<<endl;
//             }
//         }
//     }

// };

class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    void addEdge(int u,int v,bool direction){

        if(direction){
            adjList[u].push_back(v);
        }else{
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }

    }

    void printGraph(){
        for(auto &node:adjList){
            cout<<node.first;
            for(auto &nbr:node.second){
                cout<<nbr<<endl;
            }
        }
    }
};
int main(){
    Graph g;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        g.addEdge(u,v,d);
    }
    return 0;
}