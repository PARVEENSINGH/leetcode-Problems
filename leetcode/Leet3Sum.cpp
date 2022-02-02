#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        vector<vector<int>> ans;
        vector<int> res;
        int target,temp;
        for(int i =  0;i<n;i++){
            umap[nums[i]] = i;
        }

        for(int i = 0;i<n;i++){
            temp = nums[i]*-1;
            target = temp;
            for(int j = 0;j<n;j++){
                if(i==j)
                    continue;
                if(umap.find(target-nums[j])!=umap.end() && umap[target-nums[j]]!=j 
                && umap[target-nums[j]]!=i) {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(nums[target-nums[j]]);
                    ans.push_back(res);
                }
            }     
        }
        return ans;
    }
};
