
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int c=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]==arr[i])
                c++;
             if(arr[i-1]!=arr[i])   
                c=1;
        }
    }
};