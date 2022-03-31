#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = 0,j = matrix[0].size()-1;
        if(target<matrix[0][0] || target>matrix[n-1][j])
            return false;
        while(i<n && j>=0){
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target)
                j--;
            else
                i++;        
        }
        return false;
    }
};