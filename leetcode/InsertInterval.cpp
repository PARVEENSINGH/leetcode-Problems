#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int m = intervals.size();
        int i = 0;
        if(m==0){
            res.push_back(newInterval);
            return res;
        }   
        // first insert the intervals which are ending before the start of newInterval
        while(i<m && intervals[i][1]<newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }
        //if all intervals are ending before the new Interval 
        if(i>=m){
            res.push_back(newInterval);
            return res;
        }
        //Condition for overlapping 
        while(intervals[i][1]>=newInterval[0] && newInterval[1]>=intervals[i][0]){
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            i++;
            if(i>=m)
                break;
        }
        res.push_back(newInterval);
        //insert the newInterval
        while(i<m){
            res.push_back(intervals[i]);
            i++;
        } 
        return res;
    }
};