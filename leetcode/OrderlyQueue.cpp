#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        int n = s.length();
        string ans = s;
        if(k == 1){
          for(int i = 0;i<n;i++)
              ans = min(ans,s.substr(i)+s.substr(0,i));
          return ans;
        }
        else
            sort(s.begin(),s.end()); 
        return s;    
    }
};