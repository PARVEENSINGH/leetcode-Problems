#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3414/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
          vector<int> res;
      for(int i=0;i<nums.size();i++)
      {
         if(nums[abs(nums[i])-1]>0)
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
         else 
           res.push_back(abs(nums[i]));          
      }

    return res;
 
    }
};