#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3428/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        
        int mul=10;
        int n=N;
        int i=1;
        int num=1;

        vector<int> res;
        unordered_map<int,int> map;
        bool ok=true;

        while(i<=9)
        {
            num=i;
            n=N;
            
            ok=true;
            while(n-->1)
            {
                if((num%10+K>=10) && (num%10-K)<0)
                {
                    ok=false;
                     break; 
                }
                
                if(n==2 && map.find(num*mul+(num%10+K))!=map.end())
                {
                    map[num*mul+(num%10-K)]=num*mul+(num%10-K);
                    res.push_back(num*mul+(num%10-K));
                    break;
                }
                else if(n==2 && map.find(num*mul+(num%10-K))!=map.end())
                {
                    map[num*mul+(num%10+K)]=num*mul+(num%10+K);
                    res.push_back(num*mul+(num%10+K));
                    break;
                }

                num=(num%10+K<10)?num*mul+(num%10+K):num*mul+(num%10-K);
     
            }
            
             
            if(ok && map.find(num)==map.end())
            {
                map[num]=num;
                res.push_back(num);
                i++;
                continue;
            }

            i++;           
       }
        
        i=9;
        while(i>=1)
        {
            num=i;
            n=N;
            
            ok=true;
            while(n-->1)
            {
                if((num%10+K>=10) && (num%10-K)<0)
                {
                    ok=false;
                     break; 
                }
                
                if(n==2 && map.find(num*mul+(num%10+K))!=map.end())
                {
                    map[num*mul+(num%10-K)]=num*mul+(num%10-K);
                    res.push_back(num*mul+(num%10-K));
                    break;
                }
                else if(n==2 && map.find(num*mul+(num%10-K))!=map.end())
                {
                    map[num*mul+(num%10+K)]=num*mul+(num%10+K);
                    res.push_back(num*mul+(num%10+K));
                    break;
                }

                num=(num%10+K<10)?num*mul+(num%10+K):num*mul+(num%10-K);
     
            }
            
             
            if(ok && map.find(num)==map.end())
            {
                map[num]=num;
                res.push_back(num);
                i--;
                continue;
            }
            
            i--;
            
        }

        return res;
    }
};