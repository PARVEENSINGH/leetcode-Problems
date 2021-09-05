#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool a[51] = {0};
    void printlist(){
        for(int i = 0;i<51;i++)
            cout<<" "<<i<<": "<<a[i]<<", ";
        cout<<endl;
    }
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = 0;i<ranges.size();i++){
            int l = ranges[i][0];
            int r = ranges[i][1];
            while(l<=r){
                a[l++] = 1;
            }
        }
        
        printlist();
        while(left<=right){
            if(!a[left++])
                return false;
        }
       
        return true;
    }
};