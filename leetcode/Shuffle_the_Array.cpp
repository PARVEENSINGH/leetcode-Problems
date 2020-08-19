#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/shuffle-the-array/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    
      
        vector<int> res;

        int j=0;

        for(int i=n;i<2*n;i++)
        {
            res.push_back(nums[j++]);
            res.push_back(nums[i]);
            
        }

        return res;
    }
};