#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    void dfs(vector<vector<int>>& heights,int r,int c,int dest,vector<vector<int>> &ocean){
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size())
            return;
        if(heights[r][c]<dest)
            return;
        if(heights[r][c]==-1)
            return;
        ocean[r][c] = -1;        
        dfs(heights,r+1,c,heights[r][c],ocean);
        dfs(heights,r-1,c,heights[r][c],ocean);
        dfs(heights,r,c+1,heights[r][c],ocean);
        dfs(heights,r,c-1,heights[r][c],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> pacific(row,vector<int>(col,0));
        vector<vector<int>> atlantic(row,vector<int>(col,0));
        if(heights.size()==0)
            return ans;
        for(int c = 0;c<col;c++){
            dfs(heights,0,c,INT_MIN,atlantic);
            dfs(heights,row-1,c,INT_MIN,pacific);
        }    
        for(int r = 0;r<row;r++){
            dfs(heights,r,0,INT_MIN,atlantic);
            dfs(heights,r,col-1,INT_MIN,pacific);
        }

        vector<int> cordinate;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(atlantic[i][j] == -1 && pacific[i][j]==-1){
                    cordinate.clear();
                    cordinate.insert(cordinate.end(),{i,j});
                    ans.push_back(cordinate);
                }
            }
        }

        return ans;
    }
};