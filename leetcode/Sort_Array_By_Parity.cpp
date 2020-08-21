
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/featured/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3431/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int r=A.size(),i=0;

        while(i<r)
        {
            if(A[i]%2==1)
            {
                while(i<r && r--)
                {
                    if(A[r]%2==0)
                    {
                        swap(A[i],A[r]);
                        break;
                    }
                }           
            } 
               
            i++;
        }
        
        return A; 
    }
};