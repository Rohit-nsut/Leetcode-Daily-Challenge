#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
// 2458


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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

// T.C -> TLE

class Solution {
public:

int height(TreeNode*root,int d){

    if(root!=NULL && root->val == d)
    return 0;

    if(root == NULL){
        return 0;
    }

    int left = 1 + height(root->left,d);
    int right = 1 + height(root->right,d);

    return max(left,right);
}

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        int n = queries.size();

        for(int i=0;i<n;i++){
            ans.push_back(height(root,queries[i])-1);
        }

        return ans;

    }
};


// 2ND APPROACH

// T.C -> O(N);
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int maxi = 0;

        vector<int>left(1e5+1);
        vector<int>right(1e5+1);

        hei_left(root,left,0,maxi);
        maxi=0;
        hei_right(root,right,0,maxi);

        for(int i=0;i<queries.size();i++){
            queries[i] = max(left[queries[i]],right[queries[i]]);
        }

        return queries;

    }

private:
    void hei_left(TreeNode*root,vector<int>&left,int h,int &maxi){
        if(root==NULL)
        return;

        left[root->val] = maxi;
        maxi = max(maxi,h);
        hei_left(root->left,left,h+1,maxi);
        hei_left(root->right,left,h+1,maxi);
    }

    void hei_right(TreeNode*root,vector<int>&right,int h,int &maxi){
        if(root==NULL)
        return;

        right[root->val] = maxi;
        maxi = max(maxi,h);
        hei_right(root->right,right,h+1,maxi);
        hei_right(root->left,right,h+1,maxi);
    }
    
};