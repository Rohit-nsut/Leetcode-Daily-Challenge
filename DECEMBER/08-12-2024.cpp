#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-best-non-overlapping-events/
// 2054

// T.C -> O(N*LOG(N));
// S.C -> O(N);


class Solution {
public:

int upper(vector<vector<int>>&events,int i,int end){
    int s = i;
    int e = events.size()-1;
    int ans = e+1;

    while(s<=e){
        int mid = (s+e)>>1;

        if(events[mid][0] > end){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int solve(vector<vector<int>>&events,int n,int i,int cnt,vector<vector<int>>&dp){
    if(i>=n || cnt==2)
    return 0;

    if(dp[i][cnt] != -1)
    return dp[i][cnt];

    int index = upper(events,i,events[i][1]);
    int inc = events[i][2] + solve(events,n,index,cnt+1,dp);
    int exc = solve(events,n,i+1,cnt,dp);

    return dp[i][cnt] = max(inc,exc);
}

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(),events.end());
        vector<vector<int>>dp(n,vector<int>(3,-1));
        int ans = solve(events,n,0,0,dp);
        return ans;
    }
};