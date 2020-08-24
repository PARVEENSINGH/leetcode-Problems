
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n=arr.size()-1;
        int max_ele=arr[n],temp;
        
        for(int i=n;i>=0;i--)
        {
            if(i==n)
                arr[i]=-1;
            else
            {
                temp=max_ele;
                max_ele=max(max_ele,arr[i]);      
                arr[i]=temp;
            }
                
        }
        
        return arr;
    }
};