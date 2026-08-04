#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>interval={{1,3},{6,9}};
    vector<int>newinterval;
    
    int n=interval.size();
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
        if(interval[i][1]<newinterval[0]){
            res.push_back(interval[i]);
        }else if(interval[i][0]<newinterval[1]){
            break;
        }else{
            newinterval[0]=min(interval[i][0],newinterval[0]);
            newinterval[1]=max(interval[i][1],newinterval[1]);
        }
        
    }
    res.push_back(newinterval);
    while(i<n){
        res.push_back(interval[i]);
        i++;
    }
    return 0;
}