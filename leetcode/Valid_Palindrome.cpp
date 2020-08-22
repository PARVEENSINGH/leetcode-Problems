#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3411/

class Solution {
public:
    bool isPalindrome(string s) {

        int n=s.length();
        int l=0,r=n-1;
        bool ok=true;
    
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r++;
                continue;
            }
               
            else if(!((s[l]>=65 && s[l]<=90) || (s[l]>=97 && s[l]<=122) || s[l]==32))   
                l++;
            else if(!((s[r]>=65 && s[r]<=90) || (s[r]>=97 && s[r]<=122)) || s[r]==32)  
                r--;
            else
            {
                ok=false;
                break;
            }
                
        }

        return ok;

    }
};