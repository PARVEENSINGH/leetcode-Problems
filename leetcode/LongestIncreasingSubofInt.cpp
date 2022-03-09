#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-increasing-subsequence/ 


//Time Complexity:- O(N2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis[n];
        lis[0] = 1;
        for(int i = 1;i<n;i++){
            lis[i] = 1;
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i] && lis[i]<lis[j]+1) // lis[i]<lis[j]+1 this is being used to always increment the value or to keep the current but don't decrease it.
                    lis[i] = lis[j]+1;                  //or we can say always to have the max it is being used
            }
        }
        return *max_element(lis,lis+n);
    }
};

//
//Time Complexity:- O(NlogN)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int i = 1;i<nums.size();i++){
            if(vec.back()<nums[i])
                vec.push_back(nums[i]);
            else{
                int ind = lower_bound(vec.begin(),vec.end(),nums[i])-vec.begin(); //Used for Binary Search
                vec[ind-1] = nums[i];
            }    
        }
        return vec.size();
    }
};