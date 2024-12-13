#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/take-gifts-from-the-richest-pile/
// 2558

// T.C -> O(N + K*LOG(N));
// S.C -> O(N);


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto it:gifts)
        pq.push(it);

        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top));
        }

        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};