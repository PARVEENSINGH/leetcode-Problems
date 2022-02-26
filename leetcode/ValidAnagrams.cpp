#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/valid-anagram/


class Solution {
public:
    int a[26] = {0};
    bool isAnagram(string s, string t) {
        //vector<int> a(26,0);
        if(s.length()!=t.length())
            return false;
        for(int i = 0;i<s.length();i++){
            a[s[i]-'a']++;
            a[t[i]-'a']--;
        }
        return *max_element(a,a+26)==0;
    }
};
