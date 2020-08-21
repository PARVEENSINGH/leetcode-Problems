
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/572/

class Solution {
public:
   
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        int min=INT32_MAX;
        int max_val=0;

        for(int i=0;i<n;i++)
        {
            if(prices[i]<min)
                min=prices[i];
            else
                max_val=max(prices[i]-min,max_val);
                
        }

        return max_val;
    }
};