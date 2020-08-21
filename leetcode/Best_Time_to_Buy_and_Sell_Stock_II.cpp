

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
   
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int i=1;
      
        while(i<prices.size())
        {
           if(prices[i-1]<prices[i])
                res+=prices[i]-prices[i-1];
           i++; 
        }
        
        return res;
    }
};