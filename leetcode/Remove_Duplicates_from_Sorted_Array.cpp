
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
    
        int n=nums.size();
        int j=0,k=0;
        bool flag=true;

        for(int i=0;i<n;)
        {
            j=i+1;

            while(i<n-1 && j<n && nums[i]==nums[j])
                j++;
            
            if(flag)
            {
                k=i+1;
                flag=false;
            }
            
            i=j;
            
            if(j<=n-1)
                nums[k++]=nums[j]; 
            
        }
        return k;
    }
};