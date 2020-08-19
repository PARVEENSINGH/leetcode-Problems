#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
    
        int n=1;
        int res=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                n++;
                continue;
            }

            res+=((n*n)-n)/2;
            n=1;       
        }
        
        if(n>1)
            res+=((n*n)-n)/2;
        
        return res;
    }
};