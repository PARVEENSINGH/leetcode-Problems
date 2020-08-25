

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
       sort(arr.begin(),arr.end());
        int temp=arr[1]-arr[0];
       for(int i=2;i<arr.size();i++)
           if(temp!=(arr[i]-arr[i-1]))
                return false;
        return true;        
    }
};