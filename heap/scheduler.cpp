#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int main(){
    int n = 0;
    vector<char> arr = {'A','A','A','B','B','B'};
    vector<int> mp(26,0);
    for(size_t i = 0; i < arr.size(); i++){
        mp[arr[i] - 'A']++;
    }
    priority_queue<int>pq;
    for(int i=0;i<26;i++){
        if(mp[i]>0){
            pq.push(mp[i]);
        }
    }
    int time=0;
    while(!pq.empty()){
        vector<int>temp;
        for(int i=0;i<n+1;i++){
            auto val=pq.top();
            pq.pop();
            val--;
            temp.push_back(val);
        }
        for(auto f:temp){
            if(f>0){
                pq.push(f);
            }
        }
        if(pq.empty()){
            time=time+temp.size();
        }else{
            time=time+n+1;
        }
    }

    return 0;
}