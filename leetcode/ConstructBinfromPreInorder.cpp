#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* makeTree(vector<int> &preorder,int prestart,int preEnd,vector<int> &inorder, int instart,int inEnd,map<int,int> &cmap){
        if(prestart>preEnd || instart>inEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inLeftSubLen = cmap[root->val]; 
        int nodelen = inLeftSubLen - instart;
        root->left = makeTree(preorder,prestart+1,prestart+nodelen,inorder,instart,inLeftSubLen-1,cmap);
        root->right = makeTree(preorder,prestart+nodelen+1,preEnd,inorder,inLeftSubLen+1,inEnd,cmap);
        return root;    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> cmap;
        for(int  i = 0;i<inorder.size();i++)
            cmap[inorder[i]]=i;
        return makeTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,cmap);
    }
};