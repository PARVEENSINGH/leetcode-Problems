#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

class Solution {
public:
    vector<int> count;
    int total=0;
    vector<vector<int>> rect;
    Solution(vector<vector<int>>& rects) {
        
        rect=rects;
        for(int i=0;i<rects.size();i++)
        {   
            total+=(rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            count.push_back(total);
        }
    }
    
    vector<int> pick() {
        
        vector<int> res;
        int target=rand()%total;  //target denotes the nth point & now we will check that it would lie in which rectangle.
        int l=0,r=count.size()-1,mid=0;

        //Binary Search to search the random nth point would lie in which rectangle.
        while(l<=r)
        {
            mid=(r+l)/2;

            if(target>=count[mid])
                l=mid+1;
            else
                r=mid-1;
        }

        int randx=rand()%(rect[l][2]-rect[l][0]+1);
        int randy=rand()%(rect[l][3]-rect[l][1]+1);
        res.push_back(randx+rect[l][0]);
        res.push_back(randy+rect[l][1]);

        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */