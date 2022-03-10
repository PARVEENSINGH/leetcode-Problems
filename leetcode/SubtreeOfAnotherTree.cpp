#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/subtree-of-another-tree/

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
    bool checkIsSubtree(TreeNode* root, TreeNode* subRoot){
         if(!root || !subRoot) // if any of tree has reached at end
            return !root && !subRoot; //then return true if both are at end, means we got the match or the entire tree is subtree of itself case
         if(root->val == subRoot->val && checkIsSubtree(root->left,subRoot->left) && checkIsSubtree(root->right,subRoot->right))   
            return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false; //if we have traversed the entire tree of root & didn't got any match
        if(checkIsSubtree(root,subRoot))  //if subtree found from any of the root passed then job done
            return true;
        else
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);  //if subTree not found iterate from the next childs of root        
    }
};