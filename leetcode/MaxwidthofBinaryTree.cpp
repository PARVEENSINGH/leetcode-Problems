#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-width-of-binary-tree/

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

//Time Complexity O(N)
#define ull unsigned long long int
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,ull>> q;
        q.push({root,0});
        int res = 1;
        while(!q.empty()){
            int prev_nodeVal = q.front().second;
            int n = q.size();
            int lmin = 0,rmax = 0;
            for(int i = 0;i<n;i++){
                TreeNode* node = q.front().first;
                ull pidx = q.front().second-prev_nodeVal;
                q.pop();
                if(i==0)
                    lmin = pidx;
                if(i==n-1)
                    rmax = pidx; 
                if(node->left)
                    q.push({node->left,2*pidx+1}); 
                if(node->right)
                    q.push({node->right,2*pidx+2});   
            }
            res = max(rmax-lmin+1,res);
        }
        return res;
    }
};
