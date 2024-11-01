#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
//2044...


// time->complexity : O(2^n)
// space->complexity : O(n)

class Solution {
public:

int solve(vector<int>&nums,int i,int n,int a,int maxi){
    if(i>=n){
        return a == maxi ? 1 : 0;
    }

    int ex = solve(nums,i+1,n,a,maxi);

    int in = solve(nums,i+1,n,a|nums[i],maxi);

    return ex + in;

    
}

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;

        for(int i=0;i<n;i++){
            maxi |= nums[i];
        }

       
        int cnt = solve(nums,0,n,0,maxi);


        return cnt;
    }
};


// time->complexity : O(n*maxi)
// space->complexity : O(n*maxi)


class Solution {
public:

int solve(vector<int>&nums,int i,int n,int a,int maxi,vector<vector<int>>&dp){
    if(i>=n){
        return a == maxi ? 1 : 0;
    }

    if(dp[i][a] != -1)
    return dp[i][a];

    int ex = solve(nums,i+1,n,a,maxi,dp);

    int in = solve(nums,i+1,n,a|nums[i],maxi,dp);

    return dp[i][a] = ex + in;

    
}

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;

        for(int i=0;i<n;i++){
            maxi |= nums[i];
        }

        vector<vector<int>>dp(n+1,vector<int>(maxi+1,-1));

       
        int cnt = solve(nums,0,n,0,maxi,dp);


        return cnt;
    }
};