
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/569/

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n,0);    

        dp[0]=1;
        dp[1]=2;

        for(int i=2;i<n;i++)
            dp[i]=dp[i-1]+dp[i-2];

        return dp[n-1];        
    }
};


class Solution {
public:
    int climbStairs(int n) {
        int a = 1,b = 2,res = 0;
        if(n==1)
            return a;
        if(n==2)
            return b;    
       
        for(int i =3;i<n;i++){
            res = a+b;
            b = res;
            a = b;
        }
        return res;
        
    }
};