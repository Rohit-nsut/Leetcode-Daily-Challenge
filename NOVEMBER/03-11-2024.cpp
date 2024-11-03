#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-string/
// 796

// T.C -> O(N*N);
// S.C -> O(1);


class Solution {
public:
    bool rotateString(string p, string q) {
        int n = p.length();
        int j=0;
        int index=0;

        for(int i=0;i<n;i++){
            if(p[i]==q[j]){
                index=i;
                while(j<n && p[i%n] == q[j]){
                    j++;
                    i++;
                }
                if(j==n)
                return 1;
                j=0;
                i=index;
            }
        }

        return 0;
    }

};