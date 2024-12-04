#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
// 2825

// T.C -> O(N);
// S.C -> O(1);



class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        int i=0,j=0;

        while(i<n && j<m){
            char a = str1[i];
            char ch = a;
            if(a == 'z')
            ch = 'a';
            else ch++;

            if(a == str2[j] || ch == str2[j]){
                i++;j++;
            }

            else
            i++;
        }

        if(j==m)
        return true;

        return false;

    }
};