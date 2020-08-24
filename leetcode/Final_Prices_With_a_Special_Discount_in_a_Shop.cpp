#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
       int n=prices.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(prices[i]>=prices[j])
                {
                    prices[i]-=prices[j];
                    break;
                }
            }
            
        }

        return prices;
    }
};