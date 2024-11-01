#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
//2684

// T.C -> O(N*M);
// S.C -> O(N*M);

class Solution {
public:

int drow[3] = {-1,0,1};
int dcol[3] = {1,1,1};

int solve(vector<vector<int>>&grid,int row,int col,int n,int m,vector<vector<int>>&dp){
    if(row>=n || col>=m)
    return 0;

    if(dp[row][col] != -1)
    return dp[row][col];

    int include = 0;
    for(int i=0;i<3;i++){
        int nrow = drow[i] + row;
        int ncol = dcol[i] + col;
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[row][col] < grid[nrow][ncol]){
            include = max(include, 1 + solve(grid,nrow,ncol,n,m,dp));
            // cout<<include<<" ";
        }
        // len=max(len,include);
    }

    return dp[row][col] = include;
}

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        // vector<vector<int>>vis(n,vector<int>(m,0));
        // int len = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<n;i++){
           ans = max(ans,solve(grid,i,0,n,m,dp));
        }

        return ans;
    }
};