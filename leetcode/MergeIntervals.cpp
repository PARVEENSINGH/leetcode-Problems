#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
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


//check concept for comparator
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto& a, auto& b){return a[0]<b[0];});//check comparator concept
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>ans.back()[1])ans.push_back(intervals[i]);//intervals[i][0]>=ans.back()[1] wrong!
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;  
    }
};