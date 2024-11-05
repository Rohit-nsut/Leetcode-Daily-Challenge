#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
// 1957

// T.C -> O(N);
// S.C -> O(1);

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int cnt = 0;

        for(int i=0;i<n;i=i+2){
            
            if(s[i] == s[i+1]){
                continue;
            }
            else{
                cnt++;
            }
        }

        return cnt ;
    }
};