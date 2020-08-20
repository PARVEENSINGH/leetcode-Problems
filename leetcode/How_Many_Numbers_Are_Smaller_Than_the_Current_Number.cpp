
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
       int n=nums.size();

        vector<int> temp(101,0);
        vector<int> res(101,0);

        for(int i=0;i<n;i++)
            temp[nums[i]]++;
        
        for(int i=1;i<101;i++)
            res[i]=res[i-1]+temp[i-1];
    
    //To store the prefix sum. Such that we can have a track of lesser number than a particular number. which is
    //stored at corresponding indices.
        for(int i=0;i<n;i++)
           nums[i]=res[nums[i]];

        return nums;
    }
};