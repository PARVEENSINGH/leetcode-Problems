#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int binsearch(vector<int> nums,int target, int l, int r){
        int mid = 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(target == nums[mid])
                return mid;
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<nums[mid])
                    r = mid-1;
                else
                    l = mid+1;    
            }    
            else if(nums[r]>=nums[mid]){
                if(target<=nums[r] && target>nums[mid])
                    l = mid+1;
                else
                    r = mid-1;    
            }
                
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int r = nums.size()-1,l = 0;
        return binsearch(nums,target,0,r);

    }
};class Solution {
public:
    int binsearch(vector<int> nums,int target, int l, int r){
        int mid = 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(target == nums[mid])
                return mid;
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<nums[mid])
                    r = mid-1;
                else
                    l = mid+1;    
            }    
            else if(nums[r]>=nums[mid]){
                if(target<=nums[r] && target>nums[mid])
                    l = mid+1;
                else
                    r = mid-1;    
            }
                
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int r = nums.size()-1,l = 0;
        return binsearch(nums,target,0,r);

    }
};