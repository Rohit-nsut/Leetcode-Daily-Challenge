#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
//1277

// T.C -> O(N*M);
// S.C -> O(N*M);

class Solution {
public:

int solve(vector<vector<int>>&mat,int n,int m,int i,int j,vector<vector<int>>&dp){
    if(i>=n || j>=m)
    return 0;

    if(dp[i][j] != -1)
    return dp[i][j];

    int right = solve(mat,n,m,i,j+1,dp);
    int down = solve(mat,n,m,i+1,j,dp);
    int diagonal = solve(mat,n,m,i+1,j+1,dp);

    if(mat[i][j] == 1){
        return dp[i][j] = 1 + min(right,min(down,diagonal));
    }
    else{
        return dp[i][j] = 0;
    }

    
}

int tab(vector<vector<int>>&matrix){
     int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans = 0;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int right = dp[i][j+1]; // solve(mat,n,m,i,j+1);
            int down = dp[i+1][j]; // solve(mat,n,m,i+1,j);
            int diagonal = dp[i+1][j+1]; // solve(mat,n,m,i+1,j+1);

            if(matrix[i][j] == 1){
                int a = 1 + min(right,min(down,diagonal));
                ans+=a;
                dp[i][j] = a;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        // ans = solve(matrix,n,m,0,0,dp);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         ans+=solve(matrix,n,m,i,j,dp);
        //     }
        // }
        
        // solve(matrix,n,m,0,0);

        ans = tab(matrix);
        return ans;

    }
};


// 2ND APPROACH

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int mini = min(n,m);
        int cnt = 0;

        vector<vector<int>>pre(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j] = matrix[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++)
        //     cout<<pre[i][j]<<" ";
        //     cout<<endl;
        // }

        while(mini){
            for(int i=mini;i<=n;i++){
                for(int j=mini;j<=m;j++){
                    int val = pre[i][j] - pre[i-mini][j] - pre[i][j-mini] + pre[i-mini][j-mini];
                    if(val == mini*mini)
                    cnt++;
                }
            }
            mini--;
        }

        return cnt;

    }
};