#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/defuse-the-bomb/
// 1652

// T.C -> O(N*K);
// S.C -> O(1);



class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            int sum = 0;
            if(k>0){
                int j=0;
                while(j<k){
                    sum+=code[(j+i+1)%n];
                    j++;
                }
            }
            else if(k<0){
                int j=i;
                int a = abs(k);
                while(a>0){
                    sum+=code[(j+n-1)%n];
                    j--;
                    a--;
                }
            
            }

            ans.push_back(sum);
        }

        return ans;
    }
};