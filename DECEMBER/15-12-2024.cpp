#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-average-pass-ratio/
// 1792

// T.C -> O(N*LOG(N));
// S.C -> O(N);



class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,pair<double,double>>>pq;

        for(auto it:classes){
            double new_rat = (it[0]+1)/double(it[1]+1);
            double change = new_rat - (it[0]/double(it[1]));
            // cout<<new_rat<<" "<<change<<'\n';
            pq.push({change,{it[0],it[1]}});
        }

        int p = extraStudents;

        while(p--){
            auto it = pq.top();
            pq.pop();

            double new_val = (it.second.first+2)/(it.second.second+2);
            double change = new_val - (it.second.first+1)/(it.second.second+1);
            // cout<<it.second.first<<" "<<it.second.second<<'\n';

            pq.push({change,{it.second.first+1,it.second.second+1}});
        }

        double ans = 0;

        while(!pq.empty()){
            ans +=(pq.top().second.first/(pq.top().second.second));
            double a = pq.top().second.first/(pq.top().second.second);
            pq.pop();
        }

        return ans/n;
        
    }
};