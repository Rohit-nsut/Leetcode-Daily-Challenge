#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/continuous-subarrays/
// 2762

// T.C -> O(N*LOG(N));
// S.C -> O(N);


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int l=0,r=0;
        set<pair<int,int>>st;
        // int maxi = 

        while(r<n){
            st.insert({nums[r],r});
            int mini = (*st.begin()).first;
            int maxi = (*(--st.end())).first;
            // cout<<mini<<" "<<maxi<<endl;

            while(maxi-mini > 2){
                st.erase({nums[l],l});
                maxi = (*(--st.end())).first;
                mini = (*st.begin()).first;
                l++;
            }

            ans += st.size();
            r++;
        }

        return ans;
    }
};


