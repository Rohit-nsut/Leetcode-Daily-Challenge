#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/circular-sentence/
// 2490

// T.C -> O(N);
// S.C -> O(1);

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char ch;

        for(int i=0;i<n;i++){

            if(i==0 || ch == sentence[i]){
                while(i<n && sentence[i] != ' '){
                    ch = sentence[i++];
                }
            }
            else{
                return false;
            }

            // cout<<i<<" "<<ch<<" ";
        }

        if(sentence[n-1] != sentence[0])
        return false;

        return true;
    }
};