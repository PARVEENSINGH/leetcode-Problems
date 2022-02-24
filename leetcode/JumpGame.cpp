#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachableIdx = 0;
        if(nums[0]==0)
            return nums[0];
        for(int i = 0;i<nums.size();i++){
            if(i>reachableIdx)
                return false;
            if(reachableIdx<nums[i]+i)
                reachableIdx = nums[i]+i;

        }
        return true;
    }
};