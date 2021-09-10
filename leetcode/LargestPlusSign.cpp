#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    set<int> table;
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int dp[n][n];
        int M[n][n];
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                    M[i][j] = 1;    
            }
        }

        for(int i = 0;i<mines.size();i++)
                    M[mines[i][0]][mines[i][1]] = 0;
        int cnt = 0;
            for(int i = 0;i<n;i++){
                cnt = 0;
                for(int j = 0;j<n;j++){
                     cnt = (M[i][j]==1)?cnt+1:0;
                     dp[i][j] = cnt;
                }
                cnt = 0;
                for(int k  = n-1;k>=0;k--){
                    cnt = (M[i][k]==1)?cnt+1:0;
                    dp[i][k] = min(dp[i][k],cnt);
                }
            }
            cnt = 0;
            for(int j = 0;j<n;j++){
                cnt = 0;
                for(int i = 0;i<n;i++){
                    cnt = (M[i][j]==1)?cnt+1:0;
                    dp[i][j] = min(dp[i][j], cnt);
                }
                cnt = 0;
                for(int k = n-1;k>=0;k--){
                    cnt  = (M[k][j]==1)?cnt+1:0;
                    dp[k][j] = min(dp[k][j], cnt);
                    ans = max(ans,dp[k][j]);
                }
            }
            return ans;

    }
};