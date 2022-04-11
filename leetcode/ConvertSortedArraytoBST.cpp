#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* generateTree(int l,vector<int>& nums,int r){
        int mid = l+(r-l)/2;
       TreeNode * root = new TreeNode(nums[mid]);
       root->left = generateTree(l,nums,mid-1);
       root->right = generateTree(mid+1,nums,r);
       return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
         return generateTree(0,nums,nums.size()-1);  
    }
};