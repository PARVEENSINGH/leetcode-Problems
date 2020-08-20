#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/count-number-of-teams/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        // int n=rating.size();
        // int temp=0,count=0,c=0;

        // for(int i=0;i<n;i++)
        // {
        //    for(int j=i+1;j<n;j++)
        //    {
        //        for(int k=j+1;k<n;k++)
        //        {
        //            if(rating[i]<rating[j]<rating[k] || (rating[i]>rating[j]>rating[k]))
        //             count++;
        //        }
        //    }
                
        // }    
           
        // return count;    


        //Best Solution

        //It's is given that the values in rating are unique that means no repeated values are there.

        int n=rating.size();
        int res=0,small=0,large=0;

        for(int i=0;i<n;i++)
        {
            small=0;
            large=0;

            //Loop to count the lesser values present at the lesser indices than a particular index
            for(int j=0;j<i;j++)
                if(rating[j]<rating[i])
                    small++;

            //Loop to count the larger  values present at the larger  indices than a particular index
            for(int k=i+1;k<n;k++)
                if(rating[i]<rating[k])
                    large++;
            //possible combinations possible because of presence of the element at index i
            res+=(small*large)+(i-small)*(n-1-i-large);
        }
       return res; 

    }
};