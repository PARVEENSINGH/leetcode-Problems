#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/

class Solution {
public:
    int rob(vector<int>& nums) {

        int n=nums.size();
        
        if(n==0)
            return 0;

        int incl=nums[0],excl=0,temp=0;
        
        for(int i=1;i<n;i++)
        {
            temp=incl;
            incl=max(excl+nums[i],incl);
            excl=temp;
        }

       return incl;
    }
};