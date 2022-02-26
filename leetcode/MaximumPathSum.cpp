#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-tree-maximum-path-sum/


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
   
    int getMax(TreeNode* root,int &res){
        if(!root)
            return 0;
        int leftsum = getMax(root->left,res);
        int rightSum = getMax(root->right,res);
        res = max(res,leftsum+rightSum+root->val);
        return max(leftsum,rightSum)+root->val;       
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int res = 0;    
        getMax(root,res); 
        return res; 
  
    }
};