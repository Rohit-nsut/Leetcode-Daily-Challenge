#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flip-equivalent-binary-trees/
//951

// T.C -> O(N);
// S.C -> O(N);



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
class Solution {
public:

bool solve(TreeNode* root1,TreeNode*root2){
    if(root1==NULL && root2==NULL)
    return true;

    if(root1==NULL || root2==NULL)
    return false;

    // bool left = solve(root1->left)

    int a=-1,b=-1,c=-1,d=-1;
    if(root1->left)
    a=root1->left->val;
    if(root1->right)
    b=root1->right->val;
    
    if(root2->left)
    c=root2->left->val;
    if(root2->right)
    d=root2->right->val;

    bool left = false;
    bool right = false;

    if(a==c && b==d){
        left = solve(root1->left,root2->left);
        right = solve(root1->right,root2->right);
    }
    if(a==d && b==c){
        left |= solve(root1->left,root2->right);
        right |= solve(root1->right,root2->left);
    }

    return left && right;

}

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if( root1 && root2 && root1->val != root2->val)
        return false;
        return solve(root1,root2);
    }
};
