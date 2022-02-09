#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

class Solution {
public:
    priority_queue<int> pq;
    void Traversal(TreeNode* root){
        if(!root)
            return;
        Traversal(root->left);
        pq.push(-1*root->val);
        Traversal(root->right);    
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        Traversal(root);
        while(k-->0)
            pq.pop();
        return pq.top()*-1;    
    }
};