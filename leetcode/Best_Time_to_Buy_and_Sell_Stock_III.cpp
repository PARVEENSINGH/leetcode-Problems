
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int res=0,ans=0,max_val=0;

        for(int i=1;i<n;i++)
        {
            if(prices[i-1]<prices[i])
            {
                res=max(prices[i]-prices[i-1],res);

                for(int j=i+2;j<n-1;j++)
                {
                    if(prices[j-1]<prices[j])
                    {
                        ans=(prices[j]-prices[j-1],ans);
                    }
                        
                }
            }
            max_val=max(res+ans,max_val);
              
        }

        return max_val;
    }
};