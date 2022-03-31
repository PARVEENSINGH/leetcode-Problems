#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/course-schedule/


class Solution {
public:
    bool checkCycle(int id,vector<vector<int>>& adlist,vector<bool> &vis,vector<bool> &dfsvis){
        vis[id] = 1;
        dfsvis[id] = 1;
        for(auto it: adlist[id]){
            if(!vis[adlist[it]]){
                if(checkCycle(adlist[id][i], adlist,vis,dfsvis))
                    return true;

            }
            else if(dfsvis[adlist[id][i]])
                return true;
        }
        vis[id] = 0;
        return false;       
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, 0);
         vector<bool> dfsvis(numCourses, 0);
         int n = prerequisites.size();
         vector<vector<int>> adlist(numCourses);
         for(int i  = 0;i<n;i++)
            adlist[prerequisites[i][0]].push_back(prerequisites[i][1]);

         for(int i = 0;i<numCourses;i++){
             if(!vis[i]){
                 if(checkCycle(i,adlist,vis,dfsvis))
                    return false;
             }
         }

         return true;
    }
};


class Solution {
public:
    bool checkCycle(int id,vector<vector<int>>& adlist,vector<int> &vis){
        if(vis[id]==2)
            return true;
        vis[id] = 2;
        for(int i = 0;i<adlist[id].size();i++){
            if(vis[adlist[id][i]]!=1){
                if(checkCycle(adlist[id][i], adlist,vis))
                    return true;
            }
        }
        vis[id] = 1;
        return false;       
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
         int n = prerequisites.size();

         vector<vector<int>> adlist(numCourses);
         for(int i  = 0;i<n;i++)
            adlist[prerequisites[i][0]].push_back(prerequisites[i][1]);

         for(int i = 0;i<numCourses;i++){
             if(vis[i]==0){
                 if(checkCycle(i,adlist,vis))
                    return false;
             }
         }

         return true;
    }
};