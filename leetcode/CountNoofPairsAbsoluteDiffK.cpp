#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n =  nums.size();
        int a,b;
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(abs(nums[i]-nums[j])==k)
                    cnt+=1;
            }
        }
        return cnt;
    }
};