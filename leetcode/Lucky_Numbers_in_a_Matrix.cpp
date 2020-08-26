#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/lucky-numbers-in-a-matrix/


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int min=INT_MAX,k=-1,max;
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++)
        {   
            min=INT_MAX;
            max=INT_MIN;
            for(int j=0;j<c;j++)
            {
                if(min>matrix[i][j])
                {
                    min=matrix[i][j];
                    k=j;
                }
                  
            }
            for(int a=0;a<r;a++)
            {
                if(max<matrix[a][k])
                    max=matrix[a][k];
            }
            if(min==max)
                res.push_back(min);
        }
        return res;
    }
};