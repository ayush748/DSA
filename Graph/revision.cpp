#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;
template<typename t>
class Graph{
    public:
    unordered_map<t,list<t,int>>adjlist;
    void addedge(t u,t v,bool direction,int wt){
        adjlist[u].push_back({v,wt});
        if(direction){
            adjlist[v].push_back({u,wt});
        }
    }
    void printAdj(){
        for(auto i:adjlist){
            cout<<i.first<<"->"
            for(pair<t,int>nbr:i.second){
                cout<<nbr.first<<"->"<<nbr.second;
            }
        }
    }
};
int main(){
    return 0;
}