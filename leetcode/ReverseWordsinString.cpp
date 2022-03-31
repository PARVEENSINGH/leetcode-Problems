#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reverse-words-in-a-string/

//Can also be solved using stack

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string res= "";
        string temp = "";
        for(int i = n-1;i>=0;i--){
            temp = "";
            if(s[i]==' ')
                continue;
            while(i>=0 && s[i]!=' '){
                temp+=s[i];
                i--;
            }
            if(temp!=""){
                reverse(temp.begin(),temp.end());
                if(i>0)
                    res+=temp+' ';
                if(i<=0)
                     res+=temp;
            }
        }
        int l = res.length()-1;
        if(res[l]==' ')
            l--;
        return res.substr(0,l+1);
    }
};