#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
         
        int jewel[125];
        int stone[125];
        int res=0;

        memset(jewel,0,sizeof(jewel));
        memset(stone,0,sizeof(stone));

        int jl=J.length();
        int sl=S.length();

        for(int i=0;i<jl;i++)
            jewel[J[i]]=1;

        for(int i=0;i<sl;i++)
            stone[S[i]]++;  

        for(int i=64;i<125;i++)
            if(jewel[i])
                 res+=stone[i];
        
        return res;   
        
        }
};