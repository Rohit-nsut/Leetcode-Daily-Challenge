#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
//1233

// T.C -> O(N*L);
// S.C -> O(N*L);

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        int n = folder.size();
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);

        string a = folder[0];

        for(int i=1;i<n;i++){
            string p = "";
            bool f = 0;
            for(int j=0;j<folder[i].size();){
                if(j<folder[i].size())
                p+=folder[i][j++];

                while(j<folder[i].size() && folder[i][j]!='/'){
                    p+=folder[i][j];
                    j++;
                }
                if(p==a){
                    f=1;
                    break;
                }
            }
            if(f==0){
                ans.push_back(p);
                a=folder[i];
            }
        }

        return ans;

    }
};