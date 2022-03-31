#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/sort-colors/


class Solution {
public:
//Just sort
//Counting sort (in 2 passes)
//3 pointers approach

    void sortColors(vector<int>& nums) {
        int l = 0,mid = 0,h = nums.size()-1;

        while(mid<=h){
            if(nums[mid]==0)
                swap(nums[l++],nums[mid++]);
   
           else if(nums[mid]==2)
                swap(nums[mid],nums[h--]);
             
           else
                mid+=1;
        }
    }
};