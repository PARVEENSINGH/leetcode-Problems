#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool M[n][n];
        memset(M,0,sizeof(M));
        int res = n;
        for(int i = 0;i<n;i++)
            M[i][i] = 1;
        for(int i = 0;i<n-1;i++){
            if(s[i]==s[i+1]){
                M[i][i+1] = 1;    
                res++;
            }
        }
        for(int k = 2;k<n;k++){
            for(int i = 0;i<n-k;i++){
                int j = i+k;
                if(s[i]==s[j] && M[i+1][j-1]){
                    M[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};