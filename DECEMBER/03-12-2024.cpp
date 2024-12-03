#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/adding-spaces-to-a-string/
// 2109

// T.C -> O(N);
// S.C -> O(N);

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n  = spaces.size();
        ans += s.substr(0,spaces[0]);
        ans += ' ';

        for(int i=0;i<n-1;i++){
            ans += s.substr(spaces[i],spaces[i+1] - spaces[i]); 
            ans += ' ';
        }

        ans += s.substr(spaces[n-1]);

        return ans;
    }
};