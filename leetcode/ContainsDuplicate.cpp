#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i = 0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        for(auto x = 0;x<nums.size();x++)
            if(umap[x]<1)
              return true;

        return false;        
    }
};


class Solution {
public:
   
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> inset;
        for(int i = 0;i<nums.size();i++){
            if(inset.empty() || inset.find(nums[i])!=inset.end())
                return true;
            else    
                inset.insert(nums[i]);    
        }
        return false;        
    }
};