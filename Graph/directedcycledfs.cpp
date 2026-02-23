#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

template<typename t>
class Graph{
public:
    unordered_map<t,list<pair<t,int>>> adjlist;

    void addEdge(t u, t v, int wt, bool direction){
        adjlist[u].push_back({v,wt});

        // If undirected graph
        if(direction){
            adjlist[v].push_back({u,wt});
        }
    }

    void printadjlist(){
        for(auto i: adjlist){
            cout<<i.first<<" -> ";
            for(auto nbr: i.second){
                cout<<"("<<nbr.first<<","<<nbr.second<<") ";
            }
            cout<<endl;
        }
    }
    
    bool checkcycle(int node,
                    unordered_map<int,bool>& visited,
                    unordered_map<int,bool>& dfsvisited){

        visited[node]=true;
        dfsvisited[node]=true;

        for(auto nbr: adjlist[node]){
            int neighbor = nbr.first;

            if(!visited[neighbor]){
                bool cycleDetected = checkcycle(neighbor,visited,dfsvisited);
                if(cycleDetected)
                    return true;
            }
            else if(dfsvisited[neighbor]){
                return true;
            }
        }

        dfsvisited[node]=false;
        return false;
    }
};

int main(){
    Graph<int> g;

    g.addEdge(0,1,5,1);
    g.addEdge(1,2,5,1);
    g.addEdge(2,0,5,1);

    g.printadjlist();

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;

    bool ans = g.checkcycle(0,visited,dfsvisited);

    if(ans)
        cout<<"Cycle detected"<<endl;
    else
        cout<<"No cycle"<<endl;

    return 0;
}