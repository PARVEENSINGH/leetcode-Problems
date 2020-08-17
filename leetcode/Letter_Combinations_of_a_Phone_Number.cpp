
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    private:
    void _initMap(unordered_map<int,string> &map)
    {
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";
    }

    void getCombinations(vector<string> &res, string digits,
    unordered_map<int,string> &map,string cur,int index)
    {
        if(index==digits.length())
        {
            res.push_back(cur);
            return;
        }

        string root_of_each_subtree=map[digits[index]-'0'];

        for(int i=0;i<root_of_each_subtree.length();i++)
            getCombinations(res,digits,map,cur+root_of_each_subtree[i],index+1);

    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;

        if(digits.length()==0)
            return res;

         unordered_map<int,string> map;
        _initMap(map);
             
       
        getCombinations(res,digits,map,"",0);

        return res;   

    }
};