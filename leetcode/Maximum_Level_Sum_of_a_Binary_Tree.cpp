

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        
        
         if(root==NULL)
            return {};
      
        int n;
        TreeNode* Node;
        queue<TreeNode*> q;
        q.push(root);

       int res;
       int temp=0;
        int level=1;
        int max_val=INT_MIN;
        while(!q.empty())
        {
            n=q.size();
            temp=0;
            while(n--)
            {
                Node=q.front();
                q.pop();
                temp+=Node->val;
                if(Node->left!=NULL)
                    q.push(Node->left);
                if(Node->right!=NULL)
                    q.push(Node->right);    
            }
            if(max_val<temp)
            {
                max_val=temp;
                res=level;
            }
            level++;
        }
        
        return res;
    }
};