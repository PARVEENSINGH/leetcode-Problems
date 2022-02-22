#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size()-1, i =0;
        int cap = -1;
        while(i<=j){
            cap = max(cap,min(height[i],height[j])*(j-i));
            height[i]<height[j]?i++:j--;
        }
        return cap;
    }
};
