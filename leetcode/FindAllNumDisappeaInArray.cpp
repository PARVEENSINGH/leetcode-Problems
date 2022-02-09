#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //int n = nums.size();
        vector<int> res;
        sort(nums.begin(),nums.end());
        bool flag = false;
        int temp;
        for(int i = 1;i<nums.size();i++){
            temp = nums[i]-nums[i-1];
            if(temp>1){
                flag = true;
                while(temp-->1)
                    res.push_back(++nums[i-1]);
            }
        }
        if(flag)
         return res;
        res.push_back(nums[0]+1); 
        return res;
    }
};