#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int getMin(vector<int> nums, int l,int r){
        if(r<l)
            return nums[0];
        if(r==l)
            return nums[l];    
        int mid = l+(r-l)/2;
        if(mid>l && nums[mid]<nums[mid-1])
            return nums[mid];
        if(mid<r && nums[mid]>nums[mid+1])
            return nums[mid+1];
        if(nums[mid]<nums[r])
            getMin(nums,l,mid-1);
        if(nums[mid]>nums[l])
            getMin(nums,mid+1,r);        
    }
    int findMin(vector<int>& nums) {
        return getMin(nums,0,nums.size()-1);
    }
    
};