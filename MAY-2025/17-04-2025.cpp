#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-colors/
// 75...


// time->complexity : O(n)
// space->complexity : O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int z = 0;
        int t = n-1;

        for(int i=0;i<=t;){
            if(nums[i] == 0){
                swap(nums[i++],nums[z]);
                z++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[t]);
                t--;
            }
            else{
                i++;
            }
        }
    }
};