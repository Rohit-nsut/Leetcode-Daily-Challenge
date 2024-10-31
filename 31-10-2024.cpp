#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-total-distance-traveled/
// 2463

// T.C -> O(N*N);
// S.C -> O(N*N);


class Solution {
public:

long long solve(vector<int>&robot,vector<vector<int>>&factory,int i,int j,int n,int m,vector<vector<long long>>&dp){
    if(i>=n)
    return 0;

    if(j>=m)
    return 1e18;

    if(dp[i][j] != -1)
    return dp[i][j];

    long long op1 = solve(robot,factory,i,j+1,n,m,dp); 
    long long op2 = 0;

    for(int x=i;x<n;x++){
        if(factory[j][1] == x-i)
        break;

        op2 += abs(factory[j][0]-robot[x]) ;
        op1 = min(op1,op2 + solve(robot,factory,x+1,j+1,n,m,dp)); // solve(robot,factory,x+1,j+1,n,m,dp);
    }

    return dp[i][j] = op1;

}

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));

        long long ans = solve(robot,factory,0,0,n,m,dp);
        return ans;
    }
};

