#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        vector<vector<int>> ans;
        vector<int> res;
        set<vector<int>> tempset;
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
                    res.push_back(nums[umap[target-nums[j]]]);
                    sort(res.begin(),res.end()); // It is required to store the unique triplet only using set
                    tempset.insert(res); //set is being used to store the unique triplet
                    res.clear();
                }
            }     
        }
        set<vector<int> >::iterator a;
        for( a = tempset.begin();a!=tempset.end();a++){
                ans.push_back(*a);
        }
        return ans;
    }
};

//Better Approach

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> res;
        vector<vector<int>> ans;
        int l = 0,h = 0,target = 0,temp = 0;
        for(int i = 0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                l = i+1;
                h = n-1;
                target = -nums[i];
                while(l<h){
                    temp =nums[l]+nums[h];
                    if(temp==target){
                        res.insert(res.end(),{nums[i],nums[l],nums[h]}); //if multiple values needs to be inserted in vector at once.
                        // res.push_back(nums[l]);
                        // res.push_back(nums[h]);
                        ans.push_back(res);
                        res.clear();
                        while(l<h && nums[l]==nums[l+1])  //skipping the same numbers 
                            l++;
                        while(l<h && nums[h]==nums[h-1])
                            h--;
                        l++;
                        h--;        
                    }
                    else if(temp<target)
                        l++;
                    else
                        h--;    
                }
            }
        }
        return ans;
    }
};