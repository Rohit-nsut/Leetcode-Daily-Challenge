#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-characters-to-make-fancy-string/
// 1957

// T.C -> O(N);
// S.C -> O(N);


class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int n = s.length();

        for(int i=0;i<n;){
            while(i+1<n && s[i] != s[i+1]){
                ans.push_back(s[i++]);
            }
            if(i<n)
            ans.push_back(s[i]);
            if(i+1<n)
            ans.push_back(s[i+1]);
            char ch = s[i];
            i+=2;

            while(i<n && s[i] == ch){
                i++;
            }
        }
        return ans;
    }
};