    #include<bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        int cnt1[1001],cnt2[1001];
        // memset(cnt1, 0,sizeof(cnt1));
        // memset(cnt2, 0,sizeof(cnt2));
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            int cnt = 0;
            vector<int> res;
            int n1 = nums1.size(), n2 = nums2.size();
            if(n1==1 && n2 == 1){
                if(nums2[0]==nums1[0])
                    res.push_back(nums2[0]);
                return res;    
            }
            for(int i = 0 ;i<n1;i++)
                cnt1[nums1[i]]++;
            for(int j = 0;j<n2;j++)
                cnt2[nums2[j]]++;    
            for(int i = 0;i<1001;i++){
                cnt = cnt1[i]<cnt2[i]?cnt1[i]:cnt2[i];
                while (cnt--)
                    res.push_back(i);
                
            }   
            return res; 
        }
    };