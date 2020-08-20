
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

class Solution {
public:
    int subtractProductAndSum(int n) {
        
        if(n==0)
            return 0;

        int sum=0;
        int mul=1;

        while(n)
        {
            sum+=n%10;
            mul*=n%10;
            n/=10;
        }    

        return mul-sum;
    }
};