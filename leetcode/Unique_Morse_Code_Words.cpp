#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
   void _initMap(unordered_map<char,string> &map)
    {
        map['a']=".-";
        map['b']="-...";
        map['c']="-.-.";
        map['d']="-..";
        map['e']=".";
        map['f']="..-.";
        map['g']="--.";
        map['h']="....";
        map['i']="..";
        map['j']=".---";
        map['k']="-.-";
        map['l']=".-..";
        map['m']="--";
        map['n']="-.";
        map['o']="---";
        map['p']=".--.";
        map['q']="--.-";
        map['r']=".-.";
        map['s']="...";
        map['t']="-";
        map['u']="..-";
        map['v']="...-";
        map['w']=".--";
        map['x']="-..-";
        map['y']="-.--";
        map['z']="--..";
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        
        unordered_map<char,string> map;
        _initMap(map);
        unordered_map<string,string> res;
        int wl;
        string temp="";
        int count=0;

        for(int i=0;i<words.size();i++)
        {
            wl=words[i].length();
            temp="";
            for(int j=0;j<wl;j++)
                temp+=map[words[i][j]];
            if(res.find(temp)!=res.end())
                count++;
            else
                res[temp]=words[i]; 
        }
        return words.size()-count;
    }
};