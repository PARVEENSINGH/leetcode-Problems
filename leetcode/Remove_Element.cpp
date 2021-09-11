#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int bidx = n-1;
        int i = 0;
        if(n==1 && val==nums[0])
            return 0;
        if(n==1 && val!=nums[0])
            return 1;
        for(i = 0;i<=bidx;i++){
            while(bidx>=0 && nums[bidx]==val && i!=bidx){bidx--;} //i!=bidx added when i & bidx pointing to same element then 
                                                                    //need to decide that this element would fall to which side.
                                                                    //So without this bidx getting subtracted twice once here & once
                                                                    // if(nums[i]==val){
            if(bidx==-1)
                return 0; //if entire array has val only
           
            if(nums[i]==val){
                swap(nums[i],nums[bidx]);
                bidx--;
            }
        }
        return bidx+1;
    }
};