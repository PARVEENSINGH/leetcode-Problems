#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string res = "";
    TreeNode* generateTree(string data,int s,int l){
        if(s>l)
            return NULL;
        int mid = (s+l)/2;    
        TreeNode* root = new TreeNode(data[mid]);
        root->left = generateTree(data,s,mid-1);
        root->right = generateTree(data,mid+1,l);
        return root;
    }
    string serialize(TreeNode* root) {
        if(!root)
            return res;
        serialize(root->left);
        res+=root->val;
        serialize(root->right);    
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

       return generateTree(data,0,data.length()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;