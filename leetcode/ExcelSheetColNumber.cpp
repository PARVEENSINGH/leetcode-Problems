#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.length();
        if(n==0 )
            return 0;
        if(n==1)
            return columnTitle[0]-'A'+1;
        int mul = 26;
        int res = 0,l =0;
        while(l<n){
            res=res*mul+(columnTitle[l]-'A'+1);
            l++;
        }  
        return res;      
    }
};