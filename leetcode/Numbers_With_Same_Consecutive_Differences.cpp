#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/

class Solution {
 private:
    void DFS(int n,int k,int start_num,vector<int> & res)
    {
        if(n==0)
        {   
             res.push_back(start_num);
             return;
        }

        vector<int> store_next_node;

        store_next_node.push_back(start_num%10+k);
        if(k!=0)
            store_next_node.push_back(start_num%10-k);

         //This loop is applied to make the node a root of the subtree.   
        for(int i=0;i<store_next_node.size();i++)

            //This if statement is supplied to select only those numbers which are [0,9] only.
            if(store_next_node[i]>=0 && store_next_node[i]<10)
            {
                int num=start_num*10+store_next_node[i];  
                DFS(n-1,k,num,res);     
            }          
      
    }

 
public:
   
    vector<int> numsSameConsecDiff(int N, int K) {
    
     if(N==1)
         return {0,1,2,3,4,5,6,7,8,9};
       vector<int> res;  
     for(int start_num=1;start_num<10;start_num++)   
       DFS(N-1,K,start_num,res);

     return res; 
    }
};