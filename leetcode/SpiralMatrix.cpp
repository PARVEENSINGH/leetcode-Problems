#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int cnt = 0;
            int m = matrix[0].size();
            int n = matrix.size();
            cnt = m+n;
            int temp = 0;
            vector<int> ans;
            while(cnt--){
                int i,j,k,l;
                for(i = temp;i<m-temp;i++)
                    ans.push_back(matrix[temp][i]);
                    temp+=1;
                for(j = temp;j<n-temp;j++)
                    ans.push_back(matrix[j][i-1]);
                for(k = m-temp-1;k>=temp;k--)
                    ans.push_back(matrix[j-1][k]);

                for(k = m-temp-1;k>=temp;k--)
                    ans.push_back(matrix[j-1][k]);    
,
            }
    }       

   
};