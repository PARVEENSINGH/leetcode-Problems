#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
          
        int i=0;
        string res="";

        while (i<address.length())
         {
             if(address[i]=='.')
                res+="[.]";
             else
                res+=address[i];
            i++;
         }
        
        return res;
        
    }
};