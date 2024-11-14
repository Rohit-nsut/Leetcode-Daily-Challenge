#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
// 2064

// T.C -> O(N*log(e));
// S.C -> O(1);



class Solution {
public:

bool isPossible(int mid,int n,vector<int>&v){
    if(mid==0)
    return 0;
    
    for(int i=0;i<v.size();i++){
        int a = v[i];
        int d = ceil(a/(mid*1.0));
        if(n-d<0)
        return false;
        n-=d;
        // cout<<n<<" ";
        
    }
    // cout<<endl;

    return true;
}

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int s = 0;
        int e = *max_element(quantities.begin(),quantities.end());

        int ans = INT_MAX;

        while(s<=e){
            int mid = (s + (e-s)/2);
            
            if(isPossible(mid,n,quantities)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return ans;

    }
};