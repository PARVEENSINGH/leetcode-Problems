#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int n=word.length();
        int i=1;
        
        if(n==0)
            return false;
        if(n==1)
            return true;
        
        if((word[i-1]>=65 && word[i-1]<=90) && (word[i]>=65 && word[i]<=90) )
        {
            for(int i=2;i<n;i++)
            {
                if(!(word[i]>=65 && word[i]<=90))
                    return false;
            }
        }
        else if((word[i-1]>=65 && word[i-1]<=90) && (word[i]>=97 && word[i]<=122))
        {
             for(int i=2;i<n;i++)
            {
                if(!(word[i]>=97 && word[i]<=122))
                    return false;
            }   
        }
        else if((word[i-1]>=97 && word[i-1]<=122))
        {
            for(int i=1;i<n;i++)
            {
                if(!(word[i]>=97 && word[i]<=122))
                    return false;
            }
        }
        return true;
        
    }
};