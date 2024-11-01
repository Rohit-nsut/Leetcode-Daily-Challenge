#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
//1593

// T.c -> O(2^n);
// S.C -> O(n);

class Solution {
public:

void solve(string &s,unordered_map<string,bool>&mp,int i,int n,int cnt,int &ans){
    if(i>=n){
        ans = max(ans,cnt);
        return;
    }

    for(int index=1;index+i<=n;index++){
        if(mp[s.substr(i,index)] == false){
            mp[s.substr(i,index)] = true;
            solve(s,mp,i+index,n,cnt+1,ans);
            mp[s.substr(i,index)] = false;
        }       
    }

}

    int maxUniqueSplit(string s) {
        unordered_map<string,bool>mp;
        int cnt = 0;
        int ans = 0;
        solve(s,mp,0,s.length(),cnt,ans);
        return ans;
    }
};