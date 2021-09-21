#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0,res = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==0){
                res = max(res,cnt);
                cnt = 0;
            }
            else
             cnt+=1;
        }
        return max(res,cnt);
    }
};