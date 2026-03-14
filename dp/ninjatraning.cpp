#include<iostream>
#include<vector>
using namespace std;
int solve(int days,int last,vector<vector<int>>points){
    if(days==0){
        int maxi=0;
        for(int tasks=0;tasks<3;tasks++){
            if(tasks!=last){
                maxi=max(maxi,points[0][tasks]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int tasks=0;tasks<3;tasks++){
        if(tasks!=last){
            int point=points[days][tasks]+solve(days-1,last,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
}
int solvedp(int days,int last,vector<vector<int>>points,vector<vector<int>>dp){
    if(days==0){
        int maxi=0;
        for(int tasks=0;tasks<3;tasks++){
            if(tasks!=last){
                maxi=max(maxi,points[0][tasks]);

            }
        }
    }
    if(dp[days][last]!=-1){
        return dp[days][last];
    }
    int maxi=0;
    for(int tasks=0;tasks<3;tasks++){
        if(days!=tasks){
            int point=points[days][tasks]+solvedp(days-1,last,points,dp);
            maxi=max(maxi,point);
        }
    }
    dp[days][last]=maxi;
    return dp[days][last];
}
int solvebottom(vector<vector<int>>points){
    int n=points.size();
    vector<vector<int>>dp;

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    dp[day][last] = max(dp[day][last],points[day][task] + dp[day-1][task]);
                }
            }
        }
    }

    return dp[n - 1][3];

}
int spaceopt(vector<vector<int>>points){
    int n = points.size();

    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);

        for (int last = 0; last < 4; last++) {
            temp[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    temp[last] = max(temp[last],
                                     points[day][task] + prev[task]);
                }
            }
        }

        prev = temp;
    }
}
int main(){
    return 0;
}