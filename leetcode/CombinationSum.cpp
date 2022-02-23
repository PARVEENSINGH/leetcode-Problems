#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void GenerateCombinationRecursion(int idx, int target,vector<int> candidates, vector<int> ans, 
    vector<vector<int>> &res){
        if(idx==candidates.size()){
            if(target==0)
                res.push_back(ans);
            return;    
        }

        if(candidates[idx]<=target){
            ans.push_back(candidates[idx]);
            GenerateCombinationRecursion(idx,target-candidates[idx],candidates,ans,res);
            ans.pop_back();
        }
        GenerateCombinationRecursion(idx+1,target,candidates,ans,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        GenerateCombinationRecursion(0,target,candidates,ans,res);
        return res;
    }
};