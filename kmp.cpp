#include<iostream>
#include<vector>
using namespace std;
void computeLps(string pat,vector<int>& lps){
    int m=pat.length();
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<m){
        if(len!=0){
            len=lps[len-1];
        }else{
            if(len!=0){
                lps[i]=0;
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}
vector<int>search(string pat,string txt){
    int n=txt.size();
    int m=pat.size();
    vector<int>res;
    vector<int>lps(m,0);
    computeLps(pat,lps);
    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }else if(i<n && pat[j]!=txt[i]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
    return res;
}
int main(){
    
    return 0;
}