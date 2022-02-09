#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/reverse-bits/

// sliding bits of number from left to right to perform & operation with 1.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int res = 0;
        for(int i = 31;i>=0;i--){
            if((n>>i)&1)
               res|=(1<<(31-i));
        }
        return res;
    }
};

// Sliding 1 from right to left to perform & opration of 1 with every bit of number.
//Faster than above solution 

//class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int res = 0;
        for(int i = 0;i<32;i++)
            if(n & (1<<i))
                res|=(1<<(31-i));
        return res;
    }
};