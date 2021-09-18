#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        int sum = 0;
        vector<int> res;
        vector<int> empty;
        for(int i = 0;i<changed.size()-1;i++){
            for(int j = i+1;j<changed.size();j++){
                if(changed[i]>0 && changed[j]>0 && abs(changed[i]-changed[j])==min(changed[i],changed[j])){
                    res.push_back(min(changed[i],changed[j]));
                    changed[i] = -1;
                    changed[j] = -1;
                    sum-=2;
                }
            }
        }
        if(sum!= -1*n)
            return empty;
        return res;    
    }
};