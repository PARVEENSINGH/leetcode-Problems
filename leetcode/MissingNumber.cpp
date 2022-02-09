#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned int res = 0;
        int n = nums.size()-1;
        for(auto i = 0;i<nums.size();i++)
            res+=nums[i];
        int sum = (n*(n-1))/2;
        return sum-res;    
    }
};

//Second Method

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unsigned int res = nums.size();
        //int n = nums.size();
        for(int i = 0;i<nums.size();++i){
            res -= nums[i];
            res += i;
            
        }
        //int sum = (n*(n+1))/2;
        return res;    
    }
};
