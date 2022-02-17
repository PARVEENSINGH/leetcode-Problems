#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.length();
        if(n<=0)
            return res;
        bool M[n][n];
        int start = 0,len = 1;
        memset(M,0,sizeof(M));
        for(int i = 0;i<n;i++)
            M[i][i] = 1;

    //When palindromic length is 2
        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]){
                start = i;
                len = 2;
                M[i][i+1] = 1;
            }
        }

    //When palindromic length is greater tha 3, Traversing the matrix in diagonal fashion
        for(int k = 2;k<n;++k){
            for(int i = 0;i<n-k;i++){
                int j = i+k;
                if(M[i+1][j-1] && s[i]==s[j]){
                    M[i][j] = 1;
                    if(k>=len){
                        len = k+1;
                        start = i;
                    }                                                                     
                }
            }
        }
        res = s.substr(start,len);
        return res;
    }
};

// Time Complexity: O(N2)
// Space Complexity: O(N2)

class Solution {
public:
    int TraverseFromMidWhenOneCharIdDiff(string s,int l,int r){
        int n = s.length();
       
        if(n<=0 || l>r)
            return 0;
        while(l>=0 && r<n && s[l]==s[r] ){
            l--;
            r++;
        }
        return r-l-1;// Note
    }
    string longestPalindrome(string s) {
        int n = s.length(),len = 0;
        string res = "";
        if(n<=0)
            return "";

        int st = 0,end = 0;    
        for(int i = 0;i<n;i++){
           len = max(TraverseFromMidWhenOneCharIdDiff(s,i,i),TraverseFromMidWhenOneCharIdDiff(s,i,i+1));  
            // Call for the case when one char is different in palindrome
           // TraverseFromMidWhenOneCharIdDiff(s,i,i+1); //Call when mid character matching in palindrome.
           if(len>end-st){
               st = i-((len-1)/2);
               end = i+(len/2);
              // res = len;
           }
        }   
        while(st<=end){
            res+=s[st++];
        }
        return res; 
    }
};

// Time Complexity: O(N2)
// Space Complexity: O(1)