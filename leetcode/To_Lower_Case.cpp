
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string str) {
        
        int i=0,n=str.length();
       
        while(i<n)
        {
            if(str[i]>=65 && str[i]<=90)
                 str[i]+=32;
          
            i++;
        }
        
        return str;
    }
};