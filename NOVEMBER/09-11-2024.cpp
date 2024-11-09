#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-array-end/
// 3133

// T.C -> O(log(n)*27);
// S.C -> O(log(n));


class Solution {
public:
    long long minEnd(int n, int x) {
        long long num = x;
        long long ans = x;
        vector<long long>v;
        vector<long long>ind;
        int j = 0;
        long long a = 1;
        
        for(int i=0;i<=log2(n);i++){
            while((num & (a<<j)) != 0){
                // cout<<num & (1>>j)<<" r"<<" ";
                j++;
            }
            // cout<<j<<" ";
            v.push_back(pow(2,i));
            ind.push_back(j);
            j++;
           // ans = (num | (1<<j));
            
        }
        // for(auto it:v)
        // cout<<it<<" ";

        while(n>1){
            // auto index = *lower_bound(v.begin(),v.end(),n-1);
            // cout<<index<<" ";
            int index = 0;
            for(int i=0;i<v.size();i++){
                if(v[i] > n-1){
                    break;
                }
                index = v[i];
            }
            // index = log2(index);
            int i = ind[log2(index)];
            // cout<<i<<" "<<'f'<<n;
            ans = (ans | (a<<i));
            n -= index;
            // cout<<n<<endl;
        }

        return ans;
    }
};