

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        
        // int ni=indices.size(),r=0,c=0;
        // vector<vector<int>> res(n,vector<int> (m,0));
        // int ans=0;

        // for(int i=0;i<ni;i++)
        // {
        //    r=indices[i][0];
        //    c=indices[i][1];

        //    for(int j=0;j<m;j++)
        //     res[r][j]+=1;

        //    for(int k=0;k<n;k++)
        //     res[k][c]+=1; 
        // }

        // for(int i=0;i<n;i++)
        //     for(int j=0;j<m;j++)
        //         if(res[i][j]%2)
        //             ans++;

        // return ans;



        // Better Solution 

        vector<int> row(n,0);
        vector<int> col(m,0);
        int ans=0;

        for(int i=0;i<indices.size();i++)
        {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }

         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((row[i]+col[j])%2)
                    ans++;
         return ans;     
    }
};