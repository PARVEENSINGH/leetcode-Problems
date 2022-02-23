#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int res = 1,cntzero = 0;
        bool isZeroFound = false;
        vector<int> ans(nums.size(), 0);
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                isZeroFound = true;
                cntzero+=1;
                continue;
            }
            res*=nums[i];
        }
        if(cntzero>1)
            return ans;
        for(int i =0;i<nums.size();i++){
            if(isZeroFound){
                if(nums[i]==0)
                    ans[i] = res;  
            }
            else{
                ans[i] = res/nums[i];
            }
           
        }
        return ans;
    }   
};