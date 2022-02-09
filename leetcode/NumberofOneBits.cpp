#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-1-bits/
// Solved using three different methods
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        bitset<32> bset(n);
        return bset.count();
        // while(n){
        //     // res+=(n&1);
        //     // n>>=1;
        //     res++;
        //     n&=(n-1);
        // }
        // return res;
    }
};