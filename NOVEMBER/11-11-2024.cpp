#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/prime-subtraction-operation/
// 2601

// T.C -> O(N*N);
// S.C -> O(N);


class Solution {
public:

vector<int> seive(int n){

    vector<int>prime(n,true);
    prime[0]=prime[1]=false;

    int ans=0;

    for(int i=2;i*i<=n;i++){   // here optimization 2 -> i<=sqrt(n);

        if(prime[i]){
            // ans++;

            int j=i*i;  //here optimaization 1 -> j=i*i;

            while(j<n){
                prime[j]=false;
                j+=i;
            }
        }
    }

    return prime;
}

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        vector<int>prime = seive(1001);

        vector<int>v;
        for(int i=2;i<1001;i++){
            if(prime[i])
            v.push_back(i);
        }

        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1])
            continue;

            else{
                // cout<<i;
                int a = nums[i];
                int diff = nums[i] - nums[i+1];
                int pr = -1;
                for(int j=0;j<v.size();j++){
                    if(v[j] > diff){
                        pr = j;
                        break;
                    }

                }
                
                if(pr!=-1 && nums[i]-v[pr]>0){
                    nums[i]-=v[pr] ;
                }
                else
                return false;
            }
        }

        return true;
    }
};