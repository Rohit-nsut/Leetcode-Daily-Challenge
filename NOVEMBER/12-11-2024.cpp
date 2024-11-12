#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-beautiful-item-for-each-query/
// 2070

// T.C -> O(N*log(n));
// S.C -> O(N);


class Solution {
public:

int lower_bound(vector<int>&v,int a){
    int s = 0;
    int e = v.size()-1;
    int ans = 0;

    while(s<=e){
        int mid = (s + (e-s)/2);

        if(v[mid] > a){
            e = mid-1;
        }
        else{
            ans = v[mid];
            s = mid+1;
        }
    }

    return ans;
}

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int maxi = 0;
        unordered_map<int,int>mp;
        int n = items.size();
        vector<int>v;

        for(int i=0;i<n;i++){
            maxi = max(maxi,items[i][1]);
            mp[items[i][0]] = maxi;
        }

        for(auto it:mp){
            v.push_back(it.first);
        }
        sort(v.begin(),v.end());
        // for(auto it:v)
        // cout<<it<<" ";

        vector<int>ans;
        // cout<<lower_bound(v,2);

        for(auto it:queries){
            int a = lower_bound(v,it);
            // cout<<mp[a]<<" ";
            ans.push_back(mp[a]);
        }

        return ans;
    }
};