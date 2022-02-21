#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        //string s = a;
        int r = s.length()-1,l =0;
        char cl,cr;
        if(s==" " || s.length()<=0)
            return true;
        while(l<r){
            while(!((s[l]>='A' && s[l]<='Z') || (s[l]>='a' && s[l]<='z')))
                l++;
            while(!((s[r]>='A' && s[r]<='Z') || (s[r]>='a' && s[r]<='z')))
                r--;
            if(s[l]>=65 && s[l]<=90)
                s[l] = s[l]+32;
            if(s[r]>=65 && s[r]<=90) 
                s[r]  = s[r]+32;
            if(s[l]!=s[r])       
                return false;    
            l++;
            r--;    
        }
        return true;
    }
};