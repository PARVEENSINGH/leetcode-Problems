#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//      int i = 0,j = 0,k =0,l=0;
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//             int cnt = 0;
//             int m = matrix[0].size();
//             int n = matrix.size();
//             cnt = m+n;
//             int temp = 0;
//             vector<int> ans;
//             if(m==1){
//                 for(int i = 0;i<n;i++)
//                     ans.push_back(matrix[i][0]);
//                 return ans;
//             }
//             if(n==1){
//                 for(int i = 0;i<m;i++)
//                     ans.push_back(matrix[0][i]);
//                 return ans;
//             }
            
//         if(m==2 && n==2){
//             ans.push_back(matrix[0][0]);
//             ans.push_back(matrix[0][1]);
//             ans.push_back(matrix[1][1]);
//             ans.push_back(matrix[1][0]);
//             return ans;
//         }
//         int r  = n,c = m;
//             while(r/2>0 || c/2>0){
               
//                 for(i = temp;i<m-temp & c/2>0;i++){
//                     ans.push_back(matrix[temp][i]);
//                     //cnt--;
//                 }
//                 if(n==1)
//                     return ans;
//                     temp+=1;
                
//                 for(j = temp;j<=n-temp && r/2>0;j++){
//                     ans.push_back(matrix[j][i-1]);
//                    // cnt--;
//                 }
                
//                 for(k = m-temp-1;k>=temp && c/2>0;k--){
//                     ans.push_back(matrix[j-1][k]);
//                    // cnt--;
                   
//                 }

//                 for(l = n-temp;l>=temp && k>=0 && r/2>=0;l--){
//                     ans.push_back(matrix[l][k]);  
//                    // cnt--;
//                 }  
//                 //cnt/=4;
//                 r/=2;
//                 c/=2;
//                  cout<<"cnt: "<<cnt;
//             }
//             return ans;
//     }       

   
// };

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int cnt = 0;
            int m = matrix[0].size();
            int n = matrix.size();
    }
};