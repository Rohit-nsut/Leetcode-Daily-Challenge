#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// 862

// T.C -> O(N*log(N));
// S.C -> O(N);







class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        int l=0,r=0;
        long long sum = 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push({sum,i});

            if(sum>=k){
                ans = min(ans,i+1);
            }

            while(!pq.empty() && sum - pq.top().first >= k){
                ans = min(ans,i-pq.top().second);
                pq.pop();
            }
        }

        return ans==INT_MAX ? -1 : ans;
    }
};