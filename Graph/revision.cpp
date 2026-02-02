#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjlist;
    void addEdges(int u,int v,int wt,int direction){
        if(direction){
            adjlist[u].push_back({u,wt});
        }else{
            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});
        }
    }
    void printAdjList(){
        
    }
};
int main(){
    return 0;
}