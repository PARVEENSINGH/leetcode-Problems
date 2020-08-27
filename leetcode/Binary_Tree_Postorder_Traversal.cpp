

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    void Postorder(TreeNode* root,vector<int> & res)
    {
        if(root==NULL)
            return;
        Postorder(root->left,res);
        Postorder(root->right,res);

        res.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;

        Postorder(root, res);

        return res;
    }
};