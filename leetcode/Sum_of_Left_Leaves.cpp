


#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3435/

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
    void Recursion(TreeNode* root,int &res,int &count)
    {
        if(root->left==NULL && count==0)
        {
            // res+=root->val;
            count=root->val;
            return;
        }
         if(root->left==NULL)
        {
            res+=root->val;
            return;
        }
            
        Recursion(root->right,res,count);
        Recursion(root->left,res,count);    

    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0,count=0;
        Recursion(root,res,count);
        cout<<count<<" ";
        return res-count;
    }
};