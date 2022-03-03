#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    struct TrieNode{
        bool isEofWord;
        TrieNode* links[26];
        string word = "";
        bool containsKey(char c){
            return links[c-'a']!=NULL;
        }
        void getNode(char c,TrieNode* node){
            links[c-'a'] = node;
        }
    };
    TrieNode* root;
    int m,n;
    vector<string> res;
    void insertWord(string s){
        TrieNode* newnode = root;
        int i = 0;
        while(s[i]){
            if(!newnode->containsKey(s[i]))
                 newnode->getNode(s[i], new TrieNode());
            newnode = newnode->links[s[i]-'a'];
            i++;     
        }
        newnode->isEofWord = true;
        newnode->word = s;
    }

    bool isValid(int x,int y){
        if(x<0 || y<0 || x>=m || y>=n )
            return false;
        return true;    
    }

    void dfs(vector<vector<char>>& board,int x,int y,TrieNode *node){
        if(!isValid(x,y) || board[x][y]=='#' || !node->containsKey(board[x][y]))
            return;
        node = node->links[board[x][y]-'a'];  
        if(node->isEofWord){
            res.push_back(node->word);
            node->isEofWord = false;
        }
        char ch = board[x][y];
        board[x][y] = '#';
        dfs(board,x+1,y,node);
        dfs(board,x-1,y,node);
        dfs(board,x,y+1,node);
        dfs(board,x,y-1,node);    
        board[x][y] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        m = board.size();
        n = board[0].size();
        if(board.size()==0 || words.size()==0)
            return res;
        for(int i = 0;i<words.size();i++)
            insertWord(words[i]);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(root->containsKey(board[i][j]))
                    dfs(board,i,j,root);
            }
        }
        return res;
    }
};