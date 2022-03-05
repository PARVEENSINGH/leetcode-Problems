#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        vector<int> ans;
        int m = intervals.size();
        if(m==0)
            return res;
        sort(intervals.begin(),intervals.end());
        pair<int,int> mpair; // Pair taken to make one pair from all overlapping intervals
        mpair.first = intervals[0][0];
        mpair.second = intervals[0][1];
        for(auto it:intervals){
            if(it[0]<=mpair.second) //Matching overlapping interval if matched then take right max & modify the pair value.
                mpair.second = max(it[1],mpair.second); //
            else{
                res.insert(res.end(),{mpair.first,mpair.second}); // inserting the pair which is not overlapped.
                mpair.first = it[0]; // if not matched taking new pair.
                mpair.second = it[1];
            }    
        }
        res.insert(res.end(),{mpair.first,mpair.second});
        return res;
    } 
};
