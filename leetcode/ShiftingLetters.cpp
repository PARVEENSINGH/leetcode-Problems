#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        int temp;
        shifts[n-1] = shifts[n-1]%26;
        for(int i = n-2;i>=0;i--)
            shifts[i] = (shifts[i]%26 + shifts[i+1])%26;
        for(int i = 0;i<n;i++)
            s[i] = (s[i]-'a'+shifts[i])%26+'a';
        return s;
    }
};