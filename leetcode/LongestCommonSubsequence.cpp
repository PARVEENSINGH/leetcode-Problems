#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-common-subsequence/

//Brute force using recursion gives TLE
//time Complexity O(pow(2,n))
//Bottom-up Approach
class Solution {
public:
    int recursion(int i,int j,string s1,string s2){
        if(i>=s1.size() || j>=s2.size())
            return 0;
        if(s1[i]==s2[j])
            return 1+recursion(i+1,j+1,s1,s2);
        else
            return max(recursion(i+1,j,s1,s2),recursion(i,j+1,s1,s2));  
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return recursion(0,0,text1,text2);
    }
};

//Top-Down approach
class Solution {
public:
    int recursion(int i,int j,string s1,string s2){
        if(i>=s1.size() || j>=s2.size())
            return 0;
        if(s1[i]==s2[j])
            return 1+recursion(i-1,j-1,s1,s2);
        else
            return max(recursion(i-1,j,s1,s2),recursion(i,j-1,s1,s2));  
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        return recursion(text1.length()-1,text2.length()-1,text1,text2);
    }
};

//Recursive memorization

//Dynamic Programming
class Solution {
public:
    int lcsRecMemorization(int i,int j,string s1,string s2,vector<vector<int>> &vec){
        if(i>=s1.size() || j>=s2.size())
        //if(i<0 || j<0)
            return 0;
        if(vec[i][j]!=-1)
            return vec[i][j];    
        if(s1[i]==s2[j])
            return 1+lcsRecMemorization(i+1,j+1,s1,s2,vec);        
        else
            return vec[i][j] = max(lcsRecMemorization(i+1,j,s1,s2,vec),lcsRecMemorization(i,j+1,s1,s2,vec));  
        return 0;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();int n = text2.length();
        vector<vector<int>> vec(m,vector<int>(n,-1));
       return lcsRecMemorization(0,0,text1,text2,vec);
    }
};


//Iterative Dynamic programming

class Solution {
public:
    int lcsRecMemorization(int m,int n,string s1,string s2,vector<vector<int>> &vec){
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i==0 || j==0)
                    vec[i][j] = 0;
                else if(s1[i-1]==s2[j-1])
                   vec[i][j] = 1+vec[i-1][j-1]; 
                else  
                    vec[i][j] = max(vec[i-1][j],vec[i][j-1]);   
            }
        }   
        return vec[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();int n = text2.length();
        vector<vector<int>> vec(m+1,vector<int>(n+1,-1));
       return lcsRecMemorization(m,n,text1,text2,vec);
    }
};