#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int solve(int i,int c,vector<int>& arr){
        if(i==0){
            if(c==0 && arr[0]==0) return 2;
            if(c==0 || arr[0]==c) return 1;
            return 0;
        }
        int b=solve(i-1,c,arr);
        int d=0;
        if(arr[i]<=c){
            d=solve(i-1,c-arr[i],arr);
        }
        return b+d;
    }

    int solve1(int i,int c,vector<int>& arr,vector<vector<int>>& brr){
        if(i==0){
            if(c==0 && arr[0]==0) return 2;
            if(c==0 || arr[0]==c) return 1;
            return 0;
        }
        if(brr[i][c]!=-1) return brr[i][c];
        int b=solve1(i-1,c,arr,brr);
        int d=0;
        if(arr[i]<=c){
            d=solve1(i-1,c-arr[i],arr,brr);
        }
        return brr[i][c]=b+d;
    }

    int rec(vector<int>& arr,int d){
        int b=0;
        for(int i=0;i<arr.size();i++){
            b+=arr[i];
        }
        if((b+d)%2!=0 || d>b) return 0;
        int c=(b+d)/2;
        return solve(arr.size()-1,c,arr);
    }

    int memo(vector<int>& arr,int d){
        int b=0;
        for(int i=0;i<arr.size();i++){
            b+=arr[i];
        }
        if((b+d)%2!=0 || d>b) return 0;
        int c=(b+d)/2;
        int n=arr.size();
        vector<vector<int>> brr(n,vector<int>(c+1,-1));
        return solve1(n-1,c,arr,brr);
    }

    int tab(vector<int>& arr,int d){
        int b=0;
        for(int i=0;i<arr.size();i++){
            b+=arr[i];
        }
        if((b+d)%2!=0 || d>b) return 0;
        int c=(b+d)/2;
        int n=arr.size();
        vector<vector<int>> brr(n,vector<int>(c+1,0));

        if(arr[0]==0) brr[0][0]=2;
        else brr[0][0]=1;

        if(arr[0]!=0 && arr[0]<=c) brr[0][arr[0]]=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=c;j++){
                int b=brr[i-1][j];
                int d=0;
                if(arr[i]<=j){
                    d=brr[i-1][j-arr[i]];
                }
                brr[i][j]=b+d;
            }
        }
        return brr[n-1][c];
    }

    int spaceopt(vector<int>& arr,int d){
        int b=0;
        for(int i=0;i<arr.size();i++){
            b+=arr[i];
        }
        if((b+d)%2!=0 || d>b) return 0;
        int c=(b+d)/2;
        int n=arr.size();
        vector<int> brr(c+1,0);

        if(arr[0]==0) brr[0]=2;
        else brr[0]=1;

        if(arr[0]!=0 && arr[0]<=c) brr[arr[0]]=1;

        for(int i=1;i<n;i++){
            vector<int> curr(c+1,0);
            for(int j=0;j<=c;j++){
                int b=brr[j];
                int d=0;
                if(arr[i]<=j){
                    d=brr[j-arr[i]];
                }
                curr[j]=b+d;
            }
            brr=curr;
        }
        return brr[c];
    }
};

int main(){
    int n,d;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>d;

    Solution s;
    cout<<s.rec(arr,d)<<endl;
    cout<<s.memo(arr,d)<<endl;
    cout<<s.tab(arr,d)<<endl;
    cout<<s.spaceopt(arr,d)<<endl;

    return 0;
}