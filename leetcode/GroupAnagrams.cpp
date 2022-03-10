#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/group-anagrams/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> res(n);
        vector<string> ans;
        unordered_map<string, vector<string>> umap;
        string temp;
        for(int i = 0;i<n;i++){
            temp = strs[i];
            sort(temp.begin(),temp.end());
            umap[temp].push_back(strs[i]);
        }

        for(auto it = umap.begin();it!=umap.end();++it){
            res.push_back(it->second);
        }
        return res;
    }
};
