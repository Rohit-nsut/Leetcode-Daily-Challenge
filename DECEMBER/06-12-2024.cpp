#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
// 2554

// T.C -> O(N);
// S.C -> O(1);


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,bool>mp;
        for(auto it:banned){
            mp[it]=1;
        }
        int cnt = 0;
        long long sum = 0;

        for(int i=1;i<=n;i++){
            if(mp[i] == 0 && sum + i <= maxSum){
                sum += i;
                cnt++;
            }
        }

        return cnt;
    }
};