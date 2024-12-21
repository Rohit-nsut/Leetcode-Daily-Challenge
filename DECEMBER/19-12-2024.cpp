#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-chunks-to-make-sorted/
// 769

// T.C -> O(N);
// S.C -> O(1);


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int ind = 0;
        int m = arr[0];

        for(int i=0;i<n;){
            m = arr[i];
            while(i<n && i < m+1){
                m = max(m,arr[i]);
                i++;
            }
            ans++;
        }

        return ans;
    }
};