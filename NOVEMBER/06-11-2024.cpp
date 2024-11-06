#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-if-array-can-be-sorted/
// 3011

// T.C -> O(N*N);
// S.C -> O(N);


class Solution {
public:

bool solve(int a,int b){
    if((a/b == 2 && a%b==0) || (b/a == 2 && b%a==0))
    return true;

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<31;i++){
        if((a>>i) & 1){
            cnt1++;
        }
    }

    for(int i=0;i<31;i++){
        if((b>>i) & 1)
        cnt2++;
    }

    if(cnt1 == cnt2)
    return true;

    return false;
}

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>v = nums;
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
            for(int j=0;j<n-1-i;j++){
                if(j+1 < n && nums[j] > nums[j+1] && solve(nums[j],nums[j+1])){
                    // cout<<nums[j]<<" "<<nums[j+1]<<endl;
                    swap(nums[j],nums[j+1]);
                }
            }
        }


        return v == nums;
    }
};