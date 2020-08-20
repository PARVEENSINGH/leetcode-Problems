#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution {
public:
    int minOperations(int n) {

    //    int res=0;
    //     for(int i=1;i<n;i+=2)
    //         res+=n-i;   
        
    //     if(n==1)
    //         return 0;
    //     if(n==2)
    //         return 1;
    //     if(n==3)
    //         return 2;
    
    //     return res;        

    //Better Solution
    //(n-1)+(n-3)+(n-5)+.........=> n*n/4
        return n*n/4;
    }
};
