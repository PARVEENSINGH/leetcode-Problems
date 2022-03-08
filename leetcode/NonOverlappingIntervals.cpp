#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        int res = 0,i = 0,j=1;
        if(m==0 || m==1)
            return res;
        sort(intervals.begin(),intervals.end());
        while(j<m){
            if(intervals[i][1]<=intervals[j][0]){
                i = j;
                j+=1;
            }
            else if(intervals[i][1]<=intervals[j][1]){//deleting right interval because it is large
                res+=1;
                j+=1;
            }
            else if(intervals[i][1]>intervals[j][1]){  //Always deleting interval which is large, deleting left interval because it is large
                res+=1;
                i = j;
                j+=1;
            }
        } 
        return res;   
    }
};


//Another approach based on sorting of end points for each interval

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        int res = 0,i = 0,j=1;
        if(m==0 || m==1)
            return res;     
        sort(intervals.begin(),intervals.end(),[] (auto &a,auto &b){return a[1]<b[1];}); //sorting the array using comparator
        // for(i = 0;i<m;i++){
        //     cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        // }
        i = 0;
        int val = intervals[0][1];
        for(i = 1;i<m;i++){
                if(intervals[i][0]<val)
                    res++;
                else
                    val = intervals[i][1];   
        }   
        return res; 
    }
};