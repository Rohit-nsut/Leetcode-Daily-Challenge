#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
// 1415

// T.C -> O(N);
// S.C -> O(N);



//  * Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

void solve(TreeNode* root,int level){
    queue<TreeNode*>q;
    q.push(root);
    int l = 0;

    while(!q.empty()){
        int s = q.size();
        vector<TreeNode*>v;
        for(int i=0;i<s;i++){
            v.push_back(q.front());
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            q.pop();
        }

        if(l & 1){
            int s = 0;
            int e = v.size()-1;
            while(s<e){
                swap(v[s]->val,v[e]->val);
                s++;e--;
            }
        }
        l++;
    }
}

    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root,0);
        return root;
    }
};
