#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<int,list<pair<T,int>>>adjList;
    void addEdge(T u,T v,int wt,int direction)
    {
        if(direction==1){
            adjList[u].push_back({v,wt});
        }else{
            adjList[v].p
        }
    }
    
};

int main(){
    return 0;
}