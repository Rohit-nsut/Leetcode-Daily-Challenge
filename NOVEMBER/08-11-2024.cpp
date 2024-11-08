#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-xor-for-each-query/
// 1829

// T.C -> O(N*maximumBit);
// S.C -> O(N);


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>pre(n,0);
        pre[0]=nums[0];

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] ^ nums[i]; 
        }

        for(int i=0;i<n;i++){
            int a = pre[i];
            int ans = 0;
            for(int j=0;j<maximumBit;j++){
                int bit = (a>>j) & 1;
                ans = bit == 1 ? ans & ~(1<<j) : ans | (1<<j);
                // cout<<ans<<" ";
            }
            // cout<<ans<<pre[i]<<" "<<endl;
            pre[i] = ans;
        }

        reverse(pre.begin(),pre.end());

        return pre;
    }
};