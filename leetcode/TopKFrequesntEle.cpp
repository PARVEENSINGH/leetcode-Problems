#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,pair<int,int>> omap;
        vector<int> res;
        for(int i = 0;i<nums.size();i++){
            omap[nums[i]].first = nums[i];
            omap[nums[i]].second++;
        }
        for(auto x = omap.begin();x!=omap.end();x++){
            res.push_back(x)
        }
        return res;
    }
};