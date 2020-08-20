
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps (int num) {
        
        
        int res=0;
        while(num)
        {
            if(!(num%2))
            {
                num/=2;
                res++;
            }
            else
            {
              num-=1;
              res++;
            }      
        }

        return res;
    }
};