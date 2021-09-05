#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
    
   private:
    
    double Solve(vector<int> nums1,vector<int> nums2)
    {
            int n1=nums1.size();
            int n2=nums2.size(); 
            int len_half=(n1+n2+1)/2;
            int l=0;
            int r=n1;
            int maxlx=0,maxly=0,minrx=0,minry=0;
     
            while(l<=r)
            {
                int midx=(r+l)/2;
            
                int midy=len_half-midx;
            
                maxlx=(midx==0)?INT32_MIN:nums1[midx-1];
                maxly=(midy==0)?INT32_MIN:nums2[midy-1];
    
                minrx=(midx==n1)?INT32_MAX:nums1[midx];
                minry=(midy==n2)?INT32_MAX:nums2[midy];
                
                if(maxlx<=minry && maxly<=minrx)
                {     
                   
                    if((n1+n2)%2==0)
                        return (max(maxlx,maxly)+min(minrx,minry))/2.0;
                    else
                        return max(maxlx,maxly)*1.0;    
                }

                else if(maxlx>minry)
                    r=midx-1;
                else
                    l=midx+1; 
            }
      return 0.0;
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()>nums2.size())
             return Solve(nums2,nums1);
        
        return Solve(nums1,nums2);     
    }
};

// class Solution {
// public:
//     double solve(vector<int> a,vector<int> b){
//         int n1 = a.size();
//         int n2 = b.size();
//         int idxB = (n1+n2+1)/2;
//         int midx ,midy;
//         int start = 0, last = n1;
//         while(start<=last){
//             midx = (start+last)/2;
//             midy = idxB - midx;
//             int mina = (midx==0)?INT32_MIN:a[midx-1];
//             int minb = (midy ==0)?INT32_MIN:b[midy-1];

//             int maxa = (midx==n1)?INT32_MAX:a[midx];
//             int maxb = (midy==n2)?INT32_MAX:b[midy];

//             if(mina<=maxb && minb<=maxa){
//                 if((n1+n2)%2==0)
//                     return (max(mina,minb)+min(maxa,maxb))/2.0;
//                 else
//                     return max(mina,minb)*1.0;    
//             }

//             if(mina>maxb)
//                 last = midx - 1;
//             else if(minb>maxa)  //only else can be used
//                 start = midx+1; 
//         }
//         return 0.0;
//     }
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         if(nums1.size()>nums2.size())
//             return solve(nums2,nums1);
//         return solve(nums1,nums2);    
//     }
// };