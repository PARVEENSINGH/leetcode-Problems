#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/contest/weekly-contest-208/problems/crawler-log-folder/

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n  = logs.size(), m, dotc = 0, count = 0,flag = 0;
        for(int i = 0; i<n; i++)
        {
            m = logs[i].length(); 
            dotc = 0;
            flag = 0;
            for(int j=0; j<m; j++){
                if(logs[i][j] == '.')
                {
                    dotc++;
                    flag = 1;
                    continue;
                }
                else if(!flag)
                {
                    count++;
                    break;        
                }
                
            }
            if(dotc==2)
            {
                if(count>0)
                    count--;
            }

        }

        return count;
    }
};
