#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
// 2554

// T.C -> O(N);
// S.C -> O(N);


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,bool>mp;
        for(auto it:banned){
            mp[it]=1;
        }
        int cnt = 0;
        long long sum = 0;

        for(int i=1;i<=n;i++){
            if(mp[i] == 0 && sum + i <= maxSum){
                sum += i;
                cnt++;
            }
        }

        return cnt;
    }
};


// T.C -> O(N*log(N));
// S.C -> O(1);

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        sort(banned.begin(),banned.end());
        int j = 0;
        int cnt = 0;
        long long sum = 0;

        for(int i=1;i<=n;i++){
            if((j>=banned.size() || banned[j] != i) && sum + i <= maxSum){
                sum += i;
                cnt++;
            }

            else if(j<banned.size()){
                j++;
                while(j+1<banned.size()&& banned[j] == banned[j-1])
                j++;
            }
        }

        return cnt;
    }
};