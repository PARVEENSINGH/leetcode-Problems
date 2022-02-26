#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/implement-trie-prefix-tree/




class Trie {
   
public:
   struct TrieNode{
        bool isEofWord = false;
        TrieNode *Alphabet[26];
        bool containsKey(char c){
            return Alphabet[c-'a']!=NULL;
        }
        void put(char c,TrieNode* node){
            Alphabet[c-'a'] = node;
        }
        TrieNode* get(char c){
            return Alphabet[c-'a'];
        }
        void setEnd(){
            isEofWord = true;
        }
        bool getEnd(){
            return isEofWord;
        }
    };
    
    TrieNode* root;
    Trie() {
         root = new TrieNode();
    }
    void insert(string word) {
        int i = 0;
        TrieNode *newnode = root;
        while(word[i]!='\0'){
            if(!newnode->containsKey(word[i]))
                newnode->put(word[i],new TrieNode());
            newnode =  newnode->get(word[i]);
            i++;   
        }
        newnode->setEnd();
    }
    
    bool search(string word) {
        TrieNode *newnode = root;
        int i = 0;
        while(word[i]!='\0'){
            if(!newnode->containsKey(word[i]))
                return false;
            newnode = newnode->get(word[i]);
            i++;    
        }
        return newnode->getEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode *newnode = root;
        int i = 0;
        while(prefix[i]!='\0'){
            if(!newnode->containsKey(prefix[i]))
                return false;
            newnode = newnode->get(prefix[i]);
            i++;    
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */