#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    struct node{
            int num;
            int freq;
            node(int a,int b){
                num = a;
                freq = b;
            }
        };
    struct compare{
        bool operator()(node const& a,node const& b){
            return a.freq<b.freq;
        }

    };    
        
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> omap;
        vector<int> res;
        
        for(int i = 0;i<nums.size();i++)
            omap[nums[i]]++;
        priority_queue<node,vector<node>,compare> pq;    
        for(auto it:omap)
            pq.push(node(it.first,it.second));
        while(k--){
            res.push_back(pq.top().num);
            pq.pop();
        }    
        return res;
    }
};