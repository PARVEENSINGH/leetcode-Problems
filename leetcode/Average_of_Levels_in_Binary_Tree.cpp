

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
     
         if(root==NULL)
            return {};
      
        int n;
        TreeNode* Node;
        queue<TreeNode*> q;
        q.push(root);

       vector<double> res;
       double temp=0;
        int size;
        while(!q.empty())
        {
            n=q.size();
            size=n;
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
            res.push_back(temp/size);
        }
        
        return res;
    }
};