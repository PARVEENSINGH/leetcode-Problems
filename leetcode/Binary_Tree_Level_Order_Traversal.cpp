

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-tree-level-order-traversal/

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
   
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL)
            return {};
       vector<vector<int>> res;
        int n;
        TreeNode* Node;
        queue<TreeNode*> q;
        q.push(root);

        vector<int> temp;

        while(!q.empty())
        {
            n=q.size();
            temp.clear();
            while(n--)
            {
                Node=q.front();
                q.pop();
                temp.push_back(Node->val);
                if(Node->left!=NULL)
                    q.push(Node->left);
                if(Node->right!=NULL)
                    q.push(Node->right);    
            }
            res.push_back(temp);
        }
        
        return res;
    }
};