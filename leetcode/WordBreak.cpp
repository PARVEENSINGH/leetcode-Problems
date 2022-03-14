#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/word-break/


class Solution {
public:
    struct TrieNode{
        bool isEof;
        TrieNode* links[26];
        bool containsKey(char c){
            return links[c-'a']!=NULL;
        }
        void getNode(char c,TrieNode* newnode){
            links[c-'a'] = newnode;
        }
    };

    TrieNode* root;
    void insertWord(string str){
        int i = 0;
        TrieNode* newnode = root;
        while(str[i]){
            if(!newnode->containsKey(str[i]))
                newnode->getNode(str[i],new TrieNode());
            newnode = newnode->links[str[i]-'a'];
            i++;    
        }
        newnode->isEof = true;
    }
    
    bool TrieSearch(string str){
        TrieNode* node = root;
        int i = 0;
        while(str[i]){
            if(!node->containsKey(str[i]))
                return false;
            node = node->links[str[i]-'a'];
            i++;   
        }

        if(node!=NULL && node->isEof)
            return true;
        return false;    
    }

    bool WordBreakUtil(string s){
        if(s.length()==0)
            return true;
        for(int i = 0; i<s.length(); i++){
            if(TrieSearch(s.substr(0,i)) && TrieSearch(s.substr(i,s.length())))
                return true;
        }  
        return false;  
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        if(n==0)
            return false;
        root = new TrieNode();
        for(auto it:wordDict)
            insertWord(it);  
        if(root->links[s[0]-'a']==NULL) //if first char is not included in any word of Dict or  doesn't match
            return false;  
        TrieNode* node = root; 
        int i = 0; 
        return WordBreakUtil(s);  
    }
};