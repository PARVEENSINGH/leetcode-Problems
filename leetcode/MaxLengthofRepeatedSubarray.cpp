#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); int n = nums2.size();
        int a[m+1][n+1];
        int res = 0;
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                if(i==0 || j==0)
                    a[i][j] = 0;
                else if(nums1[i-1]==nums2[j-1]){
                    a[i][j] = 1+a[i-1][j-1];
                    res = max(res,a[i][j]);
                }
                else    
                    a[i][j] = 0;
            }
        }
        return res;
    }
};