#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
// 2779

// T.C -> O(N*LOG(N));
// S.C -> O(1)


class Solution {
public:

    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;

        for(int i=0;i<n;i++){
            int index = upper_bound(nums.begin(),nums.end(),nums[i]+2*k)-nums.begin();
            ans = max(ans,index-i);
        }

        return ans;
    }
};