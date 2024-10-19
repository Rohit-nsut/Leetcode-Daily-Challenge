#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
//1545

// T.C-> O(n)
// S.C-> O(n)

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)
        return '0';

        if(pow(2,n-1)-1 >= k){
            return findKthBit(n-1,k);
        }
        else if(pow(2,n-1) < k){
            return findKthBit(n-1,pow(2,n)-k) == '0' ? '1' : '0';
        }
        else{
            return '1';
        }

    }
};