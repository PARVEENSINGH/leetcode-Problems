#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        if(k<=1)
            return res;
        int left = 0,right = 0;
        long long prod = 1;
        while(right<nums.size()){
            prod*= nums[right];
            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            res+=right-left+1;
            right++;
        }
        return res;
    }
};