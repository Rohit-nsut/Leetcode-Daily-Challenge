#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/
// 3255

// T.C -> O(N);
// S.C -> O(1);


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        int l=0,r=k;
        int cnt = 1;

        for(int i=1;i<k;i++){
            if(nums[i-1]+1 != nums[i]){
                l=i;
                cnt = 1;
            }
            else{
                cnt++;
            }
        }

        if(cnt >= k){
            ans.push_back(nums[r-1]);
            // cnt--;
        }
        else{
            ans.push_back(-1);
        }

        while(r<n){
            if(nums[r-1]+1 == nums[r]){
                cnt++;
            }
            else{
                cnt = 1;
            }

            if(cnt >= k){
                ans.push_back(nums[r]);
                // cnt--;
            }
            else{
                ans.push_back(-1);
            }

            r++;
        }

        return ans;
        
    }
};