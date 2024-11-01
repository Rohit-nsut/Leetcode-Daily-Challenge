#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
// 1671

// T.C -> O(N*N*LOG(N));
// S.C -> O(N*N);


class Solution {
public:

int solveUsingRec(vector<int>&nums,int curr,int prev){
    if(curr>=nums.size()){
        return 0;
    }

    int include=0;
    if(prev==-1 || nums[prev]<nums[curr]){
        include=1 + solveUsingRec(nums,curr+1,curr);
    }

    int exclude=0 + solveUsingRec(nums,curr+1,prev);
    int ans=max(include,exclude);
    
    return ans;
}

int solveUsingMem(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
    if(curr>=nums.size()){
        return 0;
    }

    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    int include=0;
    if(prev==-1 || nums[prev]<nums[curr]){
        include=1 + solveUsingMem(nums,curr+1,curr,dp);
    }

    int exclude=0 + solveUsingMem(nums,curr+1,prev,dp);
    int ans=max(include,exclude);
    dp[curr][prev+1]=ans;

    return dp[curr][prev+1];
}

int solveUsingTabulation(vector<int>&nums,int i,int j){
    int n=j-i+1;
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int curr=n-1;curr>=0;curr--){
        for(int prev=curr-1;prev>=-1;prev--){

            int include=0;
            if(prev==-1 || nums[prev]<nums[curr]){
                include=1 + dp[curr+1][curr+1];
            }

            int exclude=0 + dp[curr+1][prev+1];
            int ans=max(include,exclude);
            dp[curr][prev+1]=ans;
        }
    }

    return dp[0][0];
}

int solveUsingBs(vector<int>&nums,int i,int j){
    vector<int>ans;
    int n = j-i+1;
    ans.push_back(nums[0]);

    for(int i=1;i<n;i++){
        if(nums[i]>ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            int index=lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
            ans[index]=nums[i];
        }
    }
    return ans.size();
}

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();;
        vector<int>v=nums;
        reverse(v.begin(),v.end());
        int ans = 0;

        for(int i=1;i<n-1;i++){
            int cnt1 = solveUsingBs(nums,0,i);
            int cnt2 = solveUsingBs(v,0,n-i-1);
            // cout<<cnt1<<" "<<cnt2<<" "<<i<<endl;

            if(cnt1==1 || cnt2==1)
            continue;

            ans = max(ans,cnt1+cnt2-1);
        }
        // cout<<ans;

        return n-ans;
    }
};