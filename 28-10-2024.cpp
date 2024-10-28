#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-square-streak-in-an-array/
//2501

// T.C -> O(N);
// S.C -> O(N);

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long,bool>mp;

        for(auto it:nums)
        mp[it]=true;

        int ans = 0;

        for(auto it:mp){
            long long num = it.first;
            int cnt = 1;
            while(mp.find(num*1ll*num) != mp.end()){
                cnt++;
                num=num*num;
            }
            ans=max(ans,cnt);
        }

        return ans == 1 ? -1 : ans;
    }
};



//APPROACH 2

// BY DP -> GIVES MLE.....


class Solution {
public:

int solve(vector<int>&nums,int n,int curr,int prev,vector<vector<int>>&dp){
    if(curr>=n)
    return 0;

    if(dp[prev+1][curr] != -1)
    return dp[prev+1][curr];

    int include = 0;

    if(prev == -1 || nums[prev]*nums[prev] == nums[curr]){
        include = 1 + solve(nums,n,curr+1,curr,dp);
    }

    int exclude = 0 + solve(nums,n,curr+1,prev,dp);

    return dp[prev+1][curr] = max(include,exclude);
}

    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int curr=0;
        int prev=-1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        int ans = solve(nums,n,curr,prev,dp);
        return ans == 1 ? -1 : ans;
    }
};