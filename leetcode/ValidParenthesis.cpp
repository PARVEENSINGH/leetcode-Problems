#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        if(s.size()<=1)
            return false;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else{
                if(!st.empty() && ((s[i] == ')' && st.top()=='(') || 
                    (s[i] == '}' && st.top() == '{' ||
                    (s[i] == ']' && st.top() == '[')))){
                        st.pop();
                        continue;
                    }
                   
                else    
                    return false;
            }    
        }
        if(st.empty())
            return true;
        return false;    
    }
};