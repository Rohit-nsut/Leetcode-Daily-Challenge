#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// 1475

// T.C -> O(N);
// S.C -> O(N);


class Solution {
public:

vector<int> nextSmallerElement(vector<int>&arr){
    stack<int>s;
    int n = arr.size();
    vector<int>v(n);
    s.push(0);

    for(int i=n-1;i>=0;i--){
        int element = arr[i];

        while(s.top() > element){
            s.pop();
        }
        v[i] = s.top();
        s.push(element);
    }
    return v;
}
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>v=nextSmallerElement(prices);
        for(int i=0;i<n;i++){
            prices[i]=prices[i] - v[i];
            // cout<<v[i]<<" ";
        }

        return prices;
    }
};