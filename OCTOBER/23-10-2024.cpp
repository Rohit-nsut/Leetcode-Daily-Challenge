#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cousins-in-binary-tree-ii/
//2641

// T.C -> O(2*N);
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



class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);
        vector<int>v;
        v.push_back(root->val);

        while(!q.empty()){
            // auto front = q.front();
            int size = q.size();
            int cnt = 0;

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                    cnt+=node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    cnt+=node->right->val;
                }
                // node->val=0 - sum;
            }
            v.push_back(cnt);
        }

        queue<pair<TreeNode*,int>>q1;

        q1.push({root,root->val});
        int i=0;

        // for(auto it:v)
        // cout<<it<<" ";
        // cout<<endl;

        while(!q1.empty()){
            // auto front = q.front();
            int size = q1.size();
            int total = v[i++];
            

            for(int i=0;i<size;i++){
                TreeNode* node = q1.front().first;
                int sum = q1.front().second;
                q1.pop();
                int p = 0;

                if(node->left){
                    p+=node->left->val;
                    // cout<<p<<' ';
                }
                if(node->right){
                    p+=node->right->val;
                    // cout<<p<<" ";
                }

                if(node->left){
                    q1.push({node->left,p});
                }
                if(node->right){
                    q1.push({node->right,p});
                }
                node->val= total - sum;
            }

        }

        // for(auto it:v)
        // cout<<it<<" ";

        return root;

    }
};