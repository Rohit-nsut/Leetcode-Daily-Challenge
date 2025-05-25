#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// 2131...


// time->complexity : O(n)
// space->complexity : O(n)

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string,int>mp;
        int n = words.size();

        for(int i=0;i<n;i++){
            string a = words[i];
            reverse(a.begin(),a.end());

            if(mp.count(a)){
                ans += 4;
                mp[a]--;

                if(mp[a] == 0)
                mp.erase(a);
            }
            else{
                mp[words[i]]++;
            }
        }

        for(auto it:mp){
            if(it.first[0] == it.first[1]){
                ans += 2;
                break;
            }
        }

        return ans;
    }
};