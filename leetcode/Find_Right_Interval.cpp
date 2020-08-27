#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/552/week-4-august-22nd-august-28th/3438/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        vector<int> res;
        int temp;
        int r=intervals.size();
        map<int,int> mapp;

        for(int i=0;i<r;i++)
            mapp[intervals[i][0]]=i;

        for(int i=0;i<r;i++)
        {    
            //All the lines can be replaced by this line
            //temp=mapp.lower_bound(intervals[i][1])!=mapp.end()?mapp.lower_bound(intervals[i][1])->second:-1;
            auto ptr=mapp.lower_bound(intervals[i][1]);
            if(ptr!=mapp.end())
                temp=ptr->second;
            else
                temp=-1;        
           res.push_back(temp);
        }
    
        return res; 
    }
};