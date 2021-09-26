#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n,cnt = 0,ans = INT_MAX ;
    void dfs(int i,int j,vector<vector<int>> &grid){
        int x[] = {-1,1,0,0};
        int y[] = {0,0,-1,1};
        if(i<m-1 && j<n-1 && grid[i][j])
            cnt+=1;
        if(i==m-1 && j==n-1){
            ans = min(ans,cnt);
            cnt = 0;
        }
        if(i<m-1 && j<n-1){
            dfs(i+x[0],j+y[0],grid);
            dfs(i+x[1],j+y[1],grid);
            dfs(i+x[2],j+y[2],grid);
            dfs(i+x[3],j+y[3],grid);
        }
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        m = grid.size();
        n = grid[0].size();
        int i = 0,j = 0;
        // while(i<m-1 && j<n-1){
            dfs(i,j,grid);
        //}
        if(ans>k)
            return -1;
        return ans;    
    }
};