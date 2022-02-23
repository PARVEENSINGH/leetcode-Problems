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
        int mul = 1,sum = 26;
        int res = 0,l =0;
        while(n--){
            res+=mul*(columnTitle[n]-'A'+1);
            mul = sum*mul;
            sum = mul;
            cout<<columnTitle[l]<<" res="<<res<<" ";
            //l++;
        }  
        return res;      
    }
};