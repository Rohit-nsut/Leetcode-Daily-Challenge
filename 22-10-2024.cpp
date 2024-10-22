#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
//2583

// T.C -> O(NLOGN);
// S.C -> O(N);


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void solve(TreeNode*root,int lvl,vector<long long>&v){
    if(root==NULL)
    return ;

    v[lvl]+=root->val;

    solve(root->left,lvl+1,v);
    solve(root->right,lvl+1,v);
}

    long long kthLargestLevelSum(TreeNode* root, int k) {
        // long long ans = 0;
        // unordered_map<int,long long>mp;
        vector<long long>v(1e5);
        solve(root,0,v);

        sort(v.begin(),v.end(),greater<>());

        return v[k-1] == 0 ? -1 : v[k-1];
    }
};