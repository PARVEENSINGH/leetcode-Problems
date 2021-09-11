#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int bidx = n-1;
        for(int i = 0;i<=bidx;i++){
            while(nums[bidx]==val){bidx--;}
            if(nums[i]==val){
                swap(nums[i],nums[bidx--]);
            }
        }
        return bidx;
    }
};