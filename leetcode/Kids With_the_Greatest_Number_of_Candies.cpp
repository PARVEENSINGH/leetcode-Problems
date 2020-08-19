#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         int n=candies.size();

        int max=*max_element(candies.begin(),candies.end());
        vector<bool> res;

        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=max)
                res.push_back(true);
            else
                res.push_back(false);     
        }

        return res;
    }
};
