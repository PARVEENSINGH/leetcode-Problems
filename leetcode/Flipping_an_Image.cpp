
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
         int n=A[0].size()-1,l=0,r;
        for(int i=0;i<A.size();i++)
        {
            l=0;
            r=n;
            while(l<r)
            {
                A[i][l]=(A[i][l]==0)?1:0;
                A[i][r]=(A[i][r]==0)?1:0;
                swap(A[i][l],A[i][r]);
                l++;
                r--;
            }
            if((n+1)%2==1)
               A[i][l]=(A[i][l]==0)?1:0;
        }
        return A;
    }
};