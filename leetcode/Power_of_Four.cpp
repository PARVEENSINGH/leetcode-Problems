
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3412/

class Solution {
public:
    bool isPowerOfFour(int num) {
        
    //  long long res=0,i=0;
    //     if(num==0)
    //         return false;
            
    //     while(res<num)
    //         res=pow(4,i++);
            
    //     return (res==num)?true:false;   

        //Best Solution
       return (num>0 && !(num & (num-1)) && num%3==1);  
    }
};