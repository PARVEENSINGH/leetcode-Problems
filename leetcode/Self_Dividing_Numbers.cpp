
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/self-dividing-numbers/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int n,a;
        bool not_self=true;
       while(left<=right)
       {
           n=left;
           not_self=true;
           if(n%10!=0)
           {
               while(n)
                {
                    a=n%10;
                    if(a==0 || left%a!=0)
                    {
                         not_self=false;
                         break;
                    }
                 
                    n/=10;           
                }
                if(not_self)
                    res.push_back(left);
           }
           
           left++;   
       }
        
     return res;
    }
};