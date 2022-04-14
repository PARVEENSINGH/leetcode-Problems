#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l = 0,r = nums.size()-1,n = nums.size();
        int temp = 0,minVal = INT_MAX,res = 0;
  
        for(int i = 0;i<n-2;i++){
            l = i+1;
            r = n-1;
            while(l<r){
                temp = nums[i]+nums[l]+nums[r];
                if(abs(temp-target)<minVal){
                    minVal = abs(temp-target);
                    res = temp;
                }
                if(temp==target)
                    return res;
                if(temp<target)
                    l++;
                if(temp>target)
                    r--;
            }
        }
        return res;
    }
};