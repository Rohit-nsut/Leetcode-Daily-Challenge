#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/string-compression-iii/
// 3163

// T.C -> O(N);
// S.C -> O(1);

class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";

        for(int i=0;i<n;i++){
            char ch = word[i];
            int cnt = 1;
            while(i+1<n && word[i] == word[i+1]){
                cnt++;
                i++;
            }
            int a = cnt/9;
            int rem = cnt%9;
            while(a--){
                ans+='9';
                ans+=ch;
            }
            if(rem){

                ans+=to_string(rem);
                ans+=ch;
            }
        }

        return ans;
    }
};