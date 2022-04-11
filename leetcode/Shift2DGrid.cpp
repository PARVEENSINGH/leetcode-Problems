#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/shift-2d-grid/


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int first,last;

        while(k--){
            first =  grid[m-1][n-1];
            for(int i = m-1;i>=0;i--){
                if(i)
                    last = grid[i-1][n-1];
                for(int j = n-2;j>=0;j--){
                    grid[i][j+1] = grid[i][j];
                }
                grid[i][0] = last;
                if(!i)
                    grid[0][0] = first;
            }
        }
        return grid;
    }
};


//Better Approach

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> res(grid);
        int m = grid.size();
        int n =  grid[0].size();
        int r,c ;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                r = (n*i+j+k)/n%m;
                c = (n*i+j+k)%n;
                res[r][c] = grid[i][j];
            }
        }

        return res;
    }
};