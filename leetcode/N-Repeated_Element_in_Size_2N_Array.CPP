#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

         int count[10000]={0};
    
            
            for(int i=0;i<A.size();i++)
            {
                if(count[A[i]]>=1)
                    return A[i];
                count[A[i]]++;
            }
                
        return 0;        
    }
};