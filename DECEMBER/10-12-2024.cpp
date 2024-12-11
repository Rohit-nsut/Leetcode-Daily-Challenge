#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/
// 2981

// T.C -> O(N*N);
// S.C -> O(N*N)



class Solution {
public:

// int check(string &s,string &str,int n){
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         string a = "";
//         for(int j=i;j<n;j++){
//             a+=s[j];
//             if(a == str)
//             cnt++;
//         }
//     }
//     return cnt;
// }

    int maximumLength(string s) {
        int n = s.length();

        int ans = -1;
        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){
            string str = "";
            for(int j=i;j<n;j++){
                str += s[j];
                mp[str]++;
            }
        }

        for(int i=0;i<n;i++){
            string str = "";
            str+=s[i];
            if(mp[str] >=3){
                ans = max(ans,1);
            }
            while(i+1<n && s[i] == s[i+1]){
                str += s[i];
                i++;
                int len = str.length();
                if(mp[str] >= 3 && ans < len){
                    ans = max(ans,len);
                }
            }

        
        }
        return ans;
    }
};