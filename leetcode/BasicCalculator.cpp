#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack<char> st;
    int calculate(string s) {
        int n = s.length();
        for(int i = 0;i<n;i++){
            while
        }
    }
};




//  int res = 0;    
//         char ch;
//         for(int i =0;i<n-1;i++){
//             if( s[i]=='-' && s[i+1]=='('){
//                 while(s[i]!=')'){
//                     if(s[i]=='-')
//                         res+=s[i+1]-'0';
//                     if(s[i]=='+')
//                         res-=s[i+1]-'0';
//                     i++;    
//                 }
//             }
//             else{
//                 if(s[i] == '+')
//                     res+=s[i+1]-'0';
//                 if(s[i]=='-')
//                     res-=s[i+1]-'0';    
//             }
//         }