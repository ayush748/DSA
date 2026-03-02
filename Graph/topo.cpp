#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
template<typename t>
class graph{
    public:
    unordered_map<t,list<pair<t,int>>>adjlist;
    void addEdge(t u,t v,bool direction){
        adjlist[u].push_back({v,wt});
        if(direction){
            adjlist[u].push({})
        }
    }
    
    
}
int main(){
    return 0;
}