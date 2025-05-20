#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/zero-array-transformation-i/
// 3355...


// time->complexity : O(n)
// space->complexity : O(n)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>v(n+2,0);

        for(auto it:queries){
            v[it[0]] -= 1;
            v[it[1]+1] += 1;
        }

        for(int i=1;i<=n;i++){
            v[i] += v[i-1];
            v[i-1] += nums[i-1];
            if(v[i-1] > 0)return false;
        }
        
        return true;

        
    }
};