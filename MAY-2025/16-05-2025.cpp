#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/
// 2901...


// time->complexity : O(n^2 * 10)
// space->complexity : O(3*n)

class Solution {
public:

bool check(string &a,string &b){
    int n = a.length();
    int m = b.length();
    if(n!=m)return false;

    int i=0;
    int cnt = 0;
    while(i<n){
        if(a[i] != b[i])cnt++;
        i++;
    }

    return cnt==1;
}

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int>dp(n,1),hash(n);
        int maxi = 0;
        vector<string>ans;
        int last = 0;
        
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && (groups[i] != groups[j])){
                    if(dp[i] < 1+dp[j]){
                        dp[i] = 1 + dp[j];
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }

        while(hash[last] != last){
            ans.push_back(words[last]);
            last = hash[last];
        }
        ans.push_back(words[last]);
        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};