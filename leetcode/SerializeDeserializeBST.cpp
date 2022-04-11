#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-bst/


//Using level order traversal

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
    string serialize(TreeNode* root) {
        string res = "";
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if(!currNode)
               res.append("#,");
            else
                res.append(to_string(currNode->val)+','); 
            if(currNode!=NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            }     
            // res+=to_string(currNode->val)+',';
            // if(!currNode->left)
            //     res+="#,";
            // else
            //     q.push(currNode->left);
            // if(!currNode->right)
            //     res+="#,";
            // else    
            //     q.push(currNode->right);            
        }
    
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;

         //Check below concept(59-61) to extract the string till a particular delimator   
        stringstream st(data);
        string str;
        getline(st,str,','); 

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            getline(st,str,',');
            if(str=="#")
                currNode->left = NULL;
            else{
                TreeNode* leftnode = new TreeNode(stoi(str));
                currNode->left = leftnode;
                q.push(currNode->left);
            }
            getline(st,str,',');
            if(str=="#")
                currNode->right = NULL;
            else{
                TreeNode* rightnode = new TreeNode(stoi(str));
                currNode->right = rightnode;
                q.push(currNode->right);
            }   
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;