#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //int n = nums.size();
        vector<int> res;
        int idx;
        for(int i = 0;i<nums.size();i++){
            idx = abs(nums[i])-1;
            nums[idx] = -1 *abs(nums[idx]);
        }

        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};