#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
// 2593

// T.C -> O(N*LOG(N));
// S.C -> O(2*N);



class Solution {
public:

// bool compare(pair<int,int>&p1,pair<int,int>&p2){
//     if(p1.first == p2.first)
//     return p1.second < p2.second;

//     return p1.first > p2.first;
// }

    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++)
        pq.push({nums[i],i});

        unordered_map<int,bool>mp;

        while(!pq.empty()){

            if(mp[pq.top().second] == true){
                pq.pop();
                continue;
            }
            auto top = pq.top();
            pq.pop();

            score += top.first;
            mp[top.second-1] = true; 
            mp[top.second+1] = true;

        }
        
        return score;
    }
};