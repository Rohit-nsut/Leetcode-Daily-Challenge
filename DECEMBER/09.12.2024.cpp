#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/special-array-ii/
// 3152

// T.C -> O(N*LOG(N));
// S.C -> O(N);



class Solution {
public:

bool isPoss(vector<pair<int,int>>&v,int s,int e){
    int n = v.size();
    int i = 0;
    int j = n-1;
                        
    while(i<=j){
        int mid = (i+j)>>1;
        if(v[mid].first >= e){
            j = mid - 1;
        }
        else if(v[mid].first < s){
            i = mid + 1;
        }
        else{
            return false;
        }
    }

    return true;
}

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,int>>parity;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]%2 == nums[i+1]%2){
                parity.push_back({i,i+1});
            }
        }
        vector<bool>ans;

        for(auto it:queries){
            int s = it[0];
            int e = it[1];
            if(isPoss(parity,s,e)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};