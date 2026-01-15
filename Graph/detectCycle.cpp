// #include<iostream>
// #include<vector>
// using namespace std;
// template<typename T>
// class Graph{
//     public:
//     unordered_map<T,list<T>>adjList;
//     void addEdge(T u, T v,int direction){
//         if(direction){
//             adjList[u].push_back(v);
//         }else{
//             adjList[u].push_back(v);
//             adjList[v].push_back(u)
//         }
//     }
//     bool CheckCycle(T src,unordered_map<T,bool>&visited){
//         unordered_map<T,T>parent;
//         queue<T>q;
//         q.push(src);
//         parent[src]=-1;
//         visited[src]=true;
//         while(!q.empty()){
//             T frontNode=q.front();
//             q.pop();
//             for(auto child:adjList[frontNode]){
//                 if(!visited[child]){
//                     q.push(child);
//                     parent[child]=frontNode;
//                     visited[src]=true;
//                 }else if(visited[child] && parent[child]!=frontNode){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
    
// };
// int main(){
//     return 0;
// }



#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_map>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>>adjList;
    void addEdge(T u,T v,bool direction){
        if(direction){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    bool checkCycleBfs(T src,unordered_map<T,list<T,bool>>&visited){
        unordered_map<T,T>parent;
        queue<T>q;
        q.push(src);
        parent[src]=-1;
        visited[src]=true;
        while(!q.empty()){
            T node=q.front();
            q.pop();
            for(auto nbr:adjList[node]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    parent[nbr]=node;
                    q.push(nbr);
                }else if(parent[node]!=nbr){
                    return true;
                }
            }
        }
        return false;
    }
    bool iscycle(){
        unordered_map<T,bool>visited;
        for(auto i:adjList){
            T node=i.first;
            if(!visited[node]){
                if(checkCycleBfs(node,visited)){
                    retrun true;
                }
            }
        }
        return false;
    }
};
int main(){

    Graph<int> g;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    if(g.iscycle()){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}