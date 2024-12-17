#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-string-with-repeat-limit/
// 2182

// T.C -> O(N*LOG(N));
// S.C -> O(N);

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();

        vector<int>fre(26,0);

        for(int i=0;i<n;i++){
            fre[s[i]-'a']++;
        }

        priority_queue<pair<char,int>>pq;
        for(int i=0;i<26;i++){
            if(fre[i] > 0)
            pq.push({'a'+i,fre[i]});
        }

        string ans = "";

        while(pq.top().second != 0){
            auto it = pq.top();
            pq.pop();

            int len = min(repeatLimit,it.second);

            for(int i=0;i<len;i++)
            ans += it.first;

            it.second -= len;
            // cout<<it.second<<" ";

            if(it.second != 0 && pq.size() > 0){
                auto next = pq.top();
                pq.pop();
                ans += next.first;
                next.second--;
                if(next.second != 0)
                pq.push({next.first,next.second});

                pq.push({it.first,it.second});
            }

            if(pq.size() == 0)
            break;

        }

        return ans;
       
    }
};