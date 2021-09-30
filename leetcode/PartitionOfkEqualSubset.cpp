#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(auto i:nums)
            sum+=nums[i++];
        if(sum%k!=0 || k==0)
            return false;   
        if(k==1)
            return true;
        bool vis = new vis[];         
    }
};