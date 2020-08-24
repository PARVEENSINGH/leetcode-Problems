#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution {
public:
    string freqAlphabets(string s) {
        
         string res="";
        int n=s.length();

        for(int i=0;i<n;)
        {
            if(i<n-2 && s[i]=='1' && s[i+2]=='#')
            {
                 res+=106+s[i+1]-'0';
                 i=i+3;
            }
               
            else if(i<n-2 && s[i]=='2' && s[i+2]=='#')
            {
                 res+=116+s[i+1]-'0';   
                 i=i+3; 
            }
               
            else
            {
                res+=96+s[i]-'0';
                i++;
            }
            
        }
        return res;
    }
};