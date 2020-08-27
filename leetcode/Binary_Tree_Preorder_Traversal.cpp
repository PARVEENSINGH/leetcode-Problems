

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        
          vector<int> res;

        if(root==NULL)
            return {};

        stack<TreeNode*> s;
        s.push(root);
        TreeNode* Node;
       
        while(!s.empty())
        {
            
            root=s.top();
            res.push_back(root->val);
             s.pop();
            if(root->right)
                s.push(root->right);
            if(root->left)
                 s.push(root->left);

        }

        return res;
    }
};