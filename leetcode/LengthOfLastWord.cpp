#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1;
        if(n==-1)
            return 0;
    
        int res = 0;
        while(n>=0){
            if(s[n] == " "){
                n--;
                if(res!=0)
                    return res;
                res = 0;
            }
            else{
                res+=1;n--;
            }

        }
        return res;
    }
};