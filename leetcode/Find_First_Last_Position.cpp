#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


class Solution {
    
   private:
    // An extra value can be added to get rightmost
int Binary_Search(int l,int r,vector<int> nums,int val, bool flag)
{
   while(l<=r)
    {
         int mid = l+(r-l)/2;
        
        
       if(nums[mid]>val || (flag && nums[mid]==val) )
            r=mid-1;
        
        else 
            l=mid+1;
    }
    return l;
}

public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> res;

        int i=Binary_Search(0,n-1,nums,target,true);

       if( i==n || nums[i]!=target)
       {
         res.push_back(-1);
         res.push_back(-1);
         return res;
       }
        
       else
       {          
           res.push_back(i);

           /*uncomment below lines to check for another approach & remove the boolean value 
           from Binarysearch method.*/

        //    while(i<n && nums[i]==target)
        //    {i++; }   
           
           res.push_back(Binary_Search(0,n-1,nums,target,false)-1);
       }
       
        return res;
    }


};

