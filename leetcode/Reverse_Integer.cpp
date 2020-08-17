
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
         int mul=10;
        long long res=0;
        while(x)
        {
            if(mul==1 && x%10==0)
            {
                x/=10;
                continue;
            }
            
            if(res*mul>INT32_MAX || res*mul<INT32_MIN)
                return 0;
            res=res*mul+x%10;
            
            x/=10;
             
        }
        int ans=res;
        return ans;
    }
};