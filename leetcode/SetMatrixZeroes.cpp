//Jan 19,22

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // priority_queue<pair<int,int>> set_tb;
    // void setAllZero(int r, int c, vector<vector<int>> & matrix){
    //     for(int i = 0;i<r;i++){
    //         for(int j = 0;j<c;j++){
    //             matrix[i][j] = 0;
    //         }
    //     }
    //     return;
    // }

    // void SetEntriesToZero(int r, int c, vector<vector<int>> & matrix){
    //         while(!set_tb.empty()){
    //             int a = set_tb.top().first;
    //             int b = set_tb.top().second;
    //             set_tb.pop();

    //             for(int i = 0;i<c;i++)
    //                 matrix[a][i] = 0;
    //             for(int i = 0;i<r;i++)
    //                 matrix[i][b] = 0;    
    //         }
    // }

    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool col = false;
        
        for(int i = 0;i<r;i++){
            if(matrix[i][0]==0)
                col = true;
            for(int j = 1;j<c;j++){
                //just marking the rows & col which needs to be zero in the ans.
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }  
            }
        }

        //1st row & 1st column being used as dummy array to mark the row & 
        //column that would be converted or filled by zero later.
        //Traversing from back because if we would start from the begining that would make dummy array updated.
        //Thus overall result would be affected & would result incorrect ans.
        
        for(int i = r-1;i>=0;i--){
            for(int j = c-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j] = 0;
            }
            //if col is true that means there is at least one zero in 1st column. 
            //Hence we are making the entire column zero here
            if(col)
                matrix[i][0] = 0;
        }
    }
};