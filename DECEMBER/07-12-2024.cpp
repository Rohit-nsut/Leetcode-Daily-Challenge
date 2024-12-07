#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
// 1760

// T.C -> O(N*LOG(N));
// S.C -> O(1);


class Solution {
public:

bool isPossible(vector<int>&nums,int mid,int x){
    for(int i=0;i<nums.size();i++){
        if(nums[i] > mid){
            int need = nums[i]/mid;
            if(nums[i]%mid == 0)
            need--;

            if(x-need>=0){
                x-=need;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int x = maxOperations;
        int maxi = *max_element(nums.begin(),nums.end());
        int s = 1;
        int e = maxi;
        int ans = INT_MAX;

        while(s<=e){
            int mid = (s+((e-s)>>1));

            if(isPossible(nums,mid,x)){
                ans = mid;
                // cout<<mid<<"d ";
                e = mid - 1;
            }
            else{
                // cout<<mid<<" ";
                s = mid + 1;
            }
        }

        return ans;
    }
};

