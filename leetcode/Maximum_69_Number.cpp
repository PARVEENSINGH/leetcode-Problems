
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) {
        
        int div=1000;
        int res=0;
        bool ok=true;
        while(num)
        {
            if(ok && num>div && num/div==6)
            {
                ok=false;
                res+=div*9;
                num%=div; 
                div/=10;
                continue;
            }
   
            res+=div*(num/div);
            num%=div; 
            div/=10;
        }
        return res;
    }
};