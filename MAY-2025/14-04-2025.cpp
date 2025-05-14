#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/
// 3337...


// time->complexity : O(t*(26+26)) -> not submitted by me it only give TLE.
// space->complexity : O(2*26)

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int n = s.length();
        vector<long long>fre(26,0);
        int mod = 1e9 + 7;

        for(auto it:s){
            fre[it-'a']++;
        }
        
        while(t--){
            vector<long long>v(26,0);
            for(int i=0;i<26;i++){
                if(fre[i] == 0)continue;

                if(i==25){
                    long long a = fre[i];
                    v[0] = (v[0] + a + mod)%mod;
                    v[nums[i]] = (v[nums[i]] - a + mod)%mod;
                }
                else{
                    long long a = fre[i];
                    
                    if(i+nums[i]+1 <= 26){
                        v[i+1] = (v[i+1] + a + mod)%mod;
                        if(i+nums[i]+1<26)
                        v[i+nums[i]+1] = (v[i+nums[i]+1] - a + mod)%mod;
                    }
                    else{
                        v[i+1] = (v[i+1] + a + mod)%mod;
                        int r = i+1+nums[i]-26;
                        v[0] = (v[0] + a + mod)%mod;
                        v[r] = (v[r] - a + mod)%mod; 
                    }

                }
            
            }

            for(int i=1;i<26;i++){
                v[i] = (v[i] + v[i-1] + mod)%mod;
            }

            fre = v;
        }


        long long ans = 0;
        for(auto it:fre){
            ans = (ans + it)%mod;
        }

        return ans;
    }
};