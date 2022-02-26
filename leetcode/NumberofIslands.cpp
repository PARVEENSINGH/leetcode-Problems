#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/number-of-islands/


class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n,m;
    
    bool isValid(int i,int j){
        if((i>=0 && j>=0) && (i<n) && j<m)
            return true;
        return false;    
    }
    
    void checkforIsland(vector<vector<char>> &grid,int x,int y){
        if(!isValid(x,y) || grid[x][y]-'0'!=1)
            return;
        grid[x][y] = '2';
        for(int i = 0;i<4;i++)
            checkforIsland(grid,x+dx[i],y+dy[i]);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]-'0'==1){
                    res+=1;
                    checkforIsland(grid,i,j);
                }
            }
        }
        
        return res;
    }
};