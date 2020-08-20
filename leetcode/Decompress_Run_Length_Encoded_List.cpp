#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        // vector<int> res;
        // int j=0;

        // for(int i=0;i<nums.size()-1;i+=2)
        // {
        //     j=0;
        //     while(j++<nums[i])
        //         res.push_back(nums[i+1]);
        // }

        //Using resize function of vector

        vector<int> res;
        
        for(int i=0;i<nums.size();i+=2)
            res.resize(res.size()+nums[i],nums[i+1]);

       return res; 
    }
};