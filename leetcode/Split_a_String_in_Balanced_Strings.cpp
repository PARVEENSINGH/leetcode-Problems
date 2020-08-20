#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/split-a-string-in-balanced-strings/

class Solution {
public:
    int balancedStringSplit(string s) {
        
        int n=s.length();
        int l=0,r=0,res=0;

        for(int i=0;i<n;i++)
        {
             if(l && l==r)
            {
                l=0;
                r=0;
                res++;
            }
            
            if(s[i]=='L')
                l++;
            else if(s[i]=='R')
                 r++;           
        }
        
        if(l && l==r)
            res++;
        
        return res;
    }
};