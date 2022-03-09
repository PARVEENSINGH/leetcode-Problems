#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/jump-game-ii/

//Approach calculate or build the dp array from back which stores minimum number of steps required from the 
//current index to destination (last index).
//So, index at 0th position will store the minimum jumps required from 1st index                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i = nums.size()-2;i>=0;i--){
            int min = 9999999;
            if(nums[i]==0){
                dp[i] = -1;
                continue;
            } 
            for(int j = 1;i+j<nums.size() && j<=nums[i];j++){ // for no. of jumps
                if(dp[i+j]!=-1 && dp[i+j]<min)
                    min = dp[i+j];
            }
            dp[i] =1+min;
        }
        return dp[0];
    }
};
