#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<pair<T,int>>>adjlist;
    void addEdge(T u,T v,int wt,bool direction){
        if(direction==1){
            adjlist[u].push_back(v);
        }else{
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(pair<T,int>nbr:i.second){
                cout<<nbr.first<<"->"<<nbr.second<<endl;
            }
            cout<<endl;
        }
    }
    
    // void bfs(T src){
    //     unordered_map<T,bool>visited;
    //     queue<T>q;
    //     q.push(src);
    //     visited[src]=true;
    //     while(!q.empty()){
    //         T frontNode=q.front();
    //         cout<<frontNode<<" ";
    //         q.pop();
    //         for(auto nbr:adjlist[frontNode]){
    //             T child=nbr.first;
    //             if(!visited[child]){
    //                 q.push(child);
    //                 visited[child]=true;
    //             }
    //         }
    //     }
    // }\

    void bfs(T src){
        unordered_map<T,bool>mp;
        queue<T>q;
        q.push(src);
        
    }
    
};
int main(){
    Graph<int>g;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        g.addEdge(u,v,wt,1);
    }
    return 0;
}