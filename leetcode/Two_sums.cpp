#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        int n=nums.size();
        vector<int> res;

        unordered_map<int,int> map={{0,-1}};
         for(int i=0;i<n;i++)
        {
             map[nums[i]]=i;
         }

        for(int i=0;i<n;i++)
        {
            if(nums[i]==target && target!=0) /* Base case not to consider the element equal 
                                                to the target value exception case when target is zero.*/
                continue;
    
                if(map.find(target-nums[i])!=map.end() && map[target-nums[i]]!=i)
                {
                    res.push_back(i);
                    res.push_back(map[target-nums[i]]);
                    break;
                }
            
        }
        return res;

    }
};