#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-k-divisible-components/
// 2872

// T.C -> O(N+M);
// S.C -> O(N+M);



class Solution {
public:

int solve(unordered_map<int,vector<int>>&adj,vector<int>&values,int k,int node,vector<bool>vis,int &ans){

    int a = values[node];

    for(auto it:adj[node]){
        // a = values[node];
        if(!vis[it]){
            vis[it] = 1;
           a += solve(adj,values,k,it,vis,ans);
           a %= k;
        }
    }

    a %= k;
    if(a == 0){
        ans++;
    }
    return a;

    
}

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // long long sum = accumulate(values.begin(),values.end(),0);
        vector<bool>vis(n,0);
        vis[0] = 1;
        int ans = 0;
        solve(adj,values,k,0,vis,ans);
        return ans;
    }
};