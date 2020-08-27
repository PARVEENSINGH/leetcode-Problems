

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    void PrintAtGivenLevel(TreeNode* root,int level,vector<int> &temp)
    {
        if(root==NULL)
            return ;
        if(level==0)
        {
            temp.push_back(root->val);
            return;
        }
          
        PrintAtGivenLevel(root->left,level-1,temp);
        PrintAtGivenLevel(root->right,level-1,temp);        
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(height(root->left),height(root->right))+1;    
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        int h=height(root);
        vector<vector<int>> res;

        for(int i=h-1;i>=0;i--)
        {   vector<int> temp;
            PrintAtGivenLevel(root,i,temp);
            res.push_back(temp);
        }

        return res;
          
    }
};