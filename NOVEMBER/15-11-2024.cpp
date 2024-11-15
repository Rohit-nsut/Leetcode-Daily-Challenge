#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
// 1574

// T.C -> O(N*log(N));
// S.C -> O(1);



class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int cnt1 = 1,cnt2 = 1,cnt3 = 1;
        int s = -1;
        int e = -1;

        for(int i=0;i<n-1;i++){
            if(arr[i] <= arr[i+1]){
                cnt1++;
            }
            else{
                s = i;
                break;
            }
        }

        for(int i=n-1;i>=1;i--){
            if(arr[i] >= arr[i-1])
            cnt2++;
            else{
                e = i;
                break;
            }
        }

        int ans = INT_MIN;
        // cout<<s<<" "<<e;

        if(cnt1==n)
        return 0;

        for(int i=e;i<n;i++){
            int l = upper_bound(arr.begin(),arr.begin()+s+1,arr[i])-arr.begin();
            
            ans = max(ans,l+n-i);
            // cout<<l<<" "<<ans<<' ';
        }

        int maxi = max(ans,max(cnt1,cnt2));

        return n - maxi;


        

        

    }
};