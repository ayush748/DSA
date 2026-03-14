#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
template<typename t>
class Graph{
    public:
    unordered_map<t,list<pair<t,int>>>adjList;
    void adjList(t u,t v,int wt,bool direction){
        adjList[u].push_back({v,wt});
        if(direction){
            adjList[v].push_back({u,wt});
        }
    }
    void bfsTravesal(t src ,unordered_map<t,bool>&visited){
        queue<t>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            t frontNode=q.front();
            cout<<frontNode<<" ";
            q.pop();
            for(auto nbr:adjedge[frontNode]){
                t child=nbr.first;
                if(!visited[child]){
                    q.push(child);
                    visited[child]=true;
                }
            }
        }
    }
    void dfsTravesal(T src,unordered_map<t,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto nbr:adjList[src]){
            t child=nbrs.first;
            if(!visited[child]){
                dfsTravesal(child,visited)
            }
        }
    }

};
int main(){
    return 0;
}