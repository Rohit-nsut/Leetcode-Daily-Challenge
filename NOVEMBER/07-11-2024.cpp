#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
// 2275

// T.C -> O(N*32);
// S.C -> O(32);

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();
        int maxi = INT_MIN;
        vector<int>v(32,0);

        for(int i=0;i<n;i++){
            int can = candidates[i];
            for(int j=0;j<31;j++){
                if((can>>j) & 1){
                    v[j]++;
                }
            }
        }

        for(auto it:v){
            maxi = max(maxi,it);
        }

        return maxi;
    }
};