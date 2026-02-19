#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<pair<T,wt>>adjList;
    void addEdge(T u,T v,int wt,bool direction){
        adjList[u].push_back({v,wt});
        if(direction){
            adjList[v].push_back({u,wt});
        }
    }
    void printadjlist(){
        for(auto i:adjlist){
            for(pair<T,int>nbr:)
        }
    }
};
int main(){
    return 0;
}