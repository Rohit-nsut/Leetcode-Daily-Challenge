#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
// 2900...


// time->complexity : O(n) 
// space->complexity : O(n)

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;

        int n = words.size();
        int c = 0;

        for(int i=0;i<n;i++){

            if(i == 0){
                c = groups[i];
                ans.push_back(words[i]);
            }
            else{
                if(groups[i] == !c){
                    ans.push_back(words[i]);
                    c = !c;
                }
            }
        }

        return ans;
    }
};