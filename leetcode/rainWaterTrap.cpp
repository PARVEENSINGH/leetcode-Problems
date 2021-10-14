#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size()-1;
        int l = 0;
        int res = 0;
        int max_left = height[0];
        int max_right = height[n];
        while(l<=n){
            if(height[l]<height[n]){
                if(max_left<height[l])
                    max_left = height[l];
                else
                    res+=max_left-height[l];
                l++;    
            }
            else{
                if(max_right<height[n])
                    max_right = height[n];
                else
                   res+=max_right-height[n];
                n--;   
            }
        }
        return res;
    }
};