#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]%2==0 && idx<n-1){
                swap(nums[idx], nums[i]);
                idx+=2;
            }
        }
    }
};