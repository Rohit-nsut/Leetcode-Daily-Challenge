#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
// 3264

// T.C -> O(N*LOG(N));
// S.C -> O(N);


class Solution {
public:

// long long pow(long long x,long long n,long long mod){
//     long long ans=1;

//     while(n>0){
//         if(n&1){
//             ans=(ans*x)%mod;
//         }
//         x=(x*x)%mod;
//         n>>1;
//     }
//     return ans%mod;

// }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        vector<int>ans(n);
        int mod=1e9+7;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        int cnt=0;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        for(int i=0;i<k;i++){
            long long top=pq.top().first;;
            long long index=pq.top().second;
            pq.pop();
            long long second=pq.top().first;
            long long x=0;
            long long divi=1;
            if(top!=0){
                divi=second/(top*multiplier);
            // cout<<"r"<<" "<<second<<" "<<top<<" "<<divi<<" ";
            }
            if(second == top*multiplier){
                x=1;
            } 
            else{
                x=max(1*1ll,divi-1);
            }
            // cout<<"divi"<<divi<<endl;//
            long long mul=pow(multiplier,x);
            top=(top*mul)%mod ;
            top%=mod;
            i+=x-1;
            // cout<<x<<" ";
            
            // pq.pop();
            pq.push({top,index});

        }

        while(!pq.empty()){
            long long top=pq.top().first;;
            long long index=pq.top().second;
            ans[index]=top%mod;
            pq.pop();
        }

        return ans;

    }
};