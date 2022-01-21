#include<bits/stdc++.h>
using namespace std;

//Approach Best with O(n). Put in map & when a character encountered which is already in map just jump to 
//the next index from the previous occurance.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.length();
        unordered_map<char,int> umap; //Is used to mark the previous occurance of a char & to jump
        int len = 0,res =0;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                if(umap.find(s[j])!=umap.end()){
                    if(umap[s[j]]>=i && umap[s[j]]<=j){
                        i = umap[s[j]]+1;
                        len = j-i; // When the occurance is included with in the sliding window.
                    }
                    else
                         len = j-i+1; //When the occureance not included in the sliding window, Hence just will update the len & update the index of occurance.
                    umap[s[j]] = j; //Updating the new occurance index.  
                }
                else{
                    umap[s[j]] = j;
                    len = j-i+1;  
                }
                res = max(res,len);   
            }
        }
        return res==0?n:res; //Used When entire string is unique.
    }
};