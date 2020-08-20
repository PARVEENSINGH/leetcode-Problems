#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
            int m=mat.size();
            int n=mat[0].size();
            cout<<m<<" ";
            int r=m-1,c=0;
            int tr=0,tc=0,k=1;
        
            vector<vector<int>> res(m,vector<int> (n,0));
            res[r][c]=mat[r][c];
            
            //iterating from 0th column & rth row.
            while(r>0)
            {
                vector<int> vec;
                r-=1;
               
                tr=r;
                tc=c;
                vec.push_back(mat[tr++][tc++]);
             
                while(tr<m && tc<n)
                  vec.push_back(mat[tr++][tc++]);
                 
                tr=r;
                tc=c;
                sort(vec.begin(),vec.end());
                for(int i=0;i<vec.size();i++)
                     res[tr++][tc++]=vec[i];

                c=0;                  
            }
        
            int a=0;
            r=0;
            tc=0;

            //iterating from cth column & 0th row.
            while(tc++<n-1)
            {
                vector<int> vec;
                a=tc;
                tr=r;
              
                while(tc<n && tr<m)
                   vec.push_back(mat[tr++][tc++]);
                tr=r;
                tc=a;
              
                sort(vec.begin(),vec.end());
                for(int i=0;i<vec.size();i++)
                     res[tr++][tc++]=vec[i];
    
                r=0;   
                tc=a;
            }
    
            return res;
        
    }
};