#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        // Solution without extra space but time complexity O(n*n) Brute force solution
        //  int n=nums.size();
        //  int l=n,r=0;
         
        //  for(int i=0;i<n-1;i++)
        //  {
        //      for(int j=i+1;j<n;j++)
        //         {
        //             if(nums[j]<nums[i])
        //             {
        //                 l=min(l,i);
        //                 r=max(j,r);
        //             }
        //         }
        //  }
        
        // return (r-l)<0 ? 0:r-l+1;
         
        
        //Solution using Extra memory Time Complexity O(nlogn)

        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++)
            temp.push_back(nums[i]);

        sort(temp.begin(),temp.end());    
        
        int i=0,j=n-1;
        for( i=0;i<n;i++)
            if(nums[i]!=temp[i])
                break;

        for(;j>=i;j--)
            if(nums[j]!=temp[j])
                break;

       return j-i+1;


       // Best Solution O(n)

  int n=nums.size();
int max_val=nums[0],min_val=nums[n-1],l=0,r=0;

for(int i=1;i<n;i++)
{
    max_val=max(max_val,nums[i]);
    min_val=min(min_val,nums[n-i-1]);

    if(nums[i]<max_val)
        l=i;
    if(nums[n-1-i]>min_val)
        r=n-i-1;    
}
return (r-l)<0?0:r-l+1;

    }
};