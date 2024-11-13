#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-fair-pairs/
// 2563

// T.C -> O(N*log(n));
// S.C -> O(1);


class Solution {
public:

int upper_bound(vector<int>&v,int h,int i){
    int s = i;
    int e = v.size()-1;
    int ans = -1;

    while(s<=e){
        int mid = (s+((e-s)>>1));
        if(v[mid] > h){
            e = mid-1;
        }
        else{
            ans = mid;
            s = mid+1;
        }
    }
    return ans;
}

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;

        // cout<<upper_bound(nums,7)<<" ";

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int l = lower - nums[i];
            int h = upper - nums[i];

            int a = upper_bound(nums,h,i+1);
            int b = lower_bound(nums.begin()+i+1,nums.end(),l)-nums.begin();
            
            if(a==-1)
            continue;

            // cout<<a<<" "<<b<<endl;

            ans+=a-b+1;

        }
        return ans;
    }
};