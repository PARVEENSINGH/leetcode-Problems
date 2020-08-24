#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> res(n,0);
        int temp=(n/2)*-1;
        for(int i=1;i<=n;i++)
        {
            if(i<=n/2)
                res[i-1]=i;    
            else
            {
                res[i-1]=temp;
                temp+=1;
            }      
        }    

        return res;
    }
};