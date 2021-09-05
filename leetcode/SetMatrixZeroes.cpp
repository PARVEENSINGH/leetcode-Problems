#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    priority_queue<pair<int,int>> set_tb;
    void setAllZero(int r, int c, vector<vector<int>> & matrix){
        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                matrix[i][j] = 0;
            }
        }
        return;
    }

    void SetEntriesToZero(int r, int c, vector<vector<int>> & matrix){
            while(!set_tb.empty()){
                int a = set_tb.top().first;
                int b = set_tb.top().second;
                set_tb.pop();

                for(int i = 0;i<c;i++)
                    matrix[a][i] = 0;
                for(int i = 0;i<r;i++)
                    matrix[i][b] = 0;    
            }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool isEntireRowzero = false;
        bool flag = false;
        for(int i = 0;i<r;i++){
            flag = false;
            for(int j =  0;j<c;j++){
                if(matrix[i][j]==0){
                    set_tb.push(make_pair(i,j));
                    continue;
                }
                else
                    flag = true;
            }
            if(!flag)
                return setAllZero(r,c,matrix);
        }

        SetEntriesToZero(r,c,matrix);
    }
};