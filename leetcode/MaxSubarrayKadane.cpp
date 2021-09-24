#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_val = nums[0];
        int val = nums[0];
        for(int i = 1;i<nums.size();i++){
            val+=nums[i];
            val = max(val,nums[i]);
            max_val = max(max_val,val);
           
        }
        return max_val;
    }
};