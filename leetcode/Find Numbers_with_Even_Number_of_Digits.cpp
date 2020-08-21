#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
         int n=nums.size();
        int res=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>=10 && nums[i]<=99)
                res++;
            else if(nums[i]>=1000 && nums[i]<=9999)   
                res++;
            else if(nums[i]>=100000 && nums[i]<=999999)
                res++;
        }   

        return res;
        
    }
};