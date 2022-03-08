#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/validate-binary-search-tree/

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
    bool checkValidBST(TreeNode* root,long long int minv,long long int maxv){
        if(!root)
            return true;  
        if(root->val>=maxv || root->val <=minv) 
            return false;
        return checkValidBST(root->left,minv,root->val) && checkValidBST(root->right,root->val,maxv);        
    }
    bool isValidBST(TreeNode* root) {
        if(!root )
            return true;
        return checkValidBST(root,INT64_MIN,INT64_MAX);    //Simple thing to check the valid BST
        //All the values in left subtree should be less than root, & in right subtree all values should be greater than the root value.
    }
};