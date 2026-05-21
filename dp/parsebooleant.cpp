#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int isTrue,string &exp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return exp[i]=='T'?1:0;
        }else{
            return exp[j]=='F'?1:0;
        }
    }
    int ways=0;
    for(int ind=i+1;ind<=j-1;ind++){
        int lt=solve(i,ind-1,1,exp);
        int lf=solve(i,ind-1,0,exp);
        int rt=solve(ind+1,j,1,exp);
        int rf=solve(ind+1,j,0,exp);
        if(exp[ind]=='&'){
            if(isTrue){
               ways=(ways+(lt*rt)); 
            }else{
                ways=(ways+(lf*rt)+(lt*rf)+(lf*rf));
            }
        }
        else if(exp[ind]=='|'){
            if(isTrue){
                ways=(ways+(lf*rt)+(lt*rf)+(rt*rt));
            }else{
                ways=(ways+(lf*rf));
            }
        }else{
            if(isTrue){
                ways=ways+(lf*rt)+(lt*rf);
            }else{
                ways=ways+(lf*rf)+(lt*rt);
            }
        }
    }

    return ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    return solve(0, n - 1, 1, exp);
}
int main(){
    return 0;
}