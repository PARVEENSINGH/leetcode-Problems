#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> ans(n+1,0);
       ans[0] = 0;
       int i = 1;
       while(i<=n){
           if(i%2)
               ans[i] = 1+ans[i/2];
           else
               ans[i] = ans[i/2]; 
       }
       return ans;
    }
};