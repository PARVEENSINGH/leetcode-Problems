#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> res = {""};
        int ans = 0;
        for(string word:arr){

            for(int i = 0;i<res.size();i++){
                string temp = res[i]+word;
                unordered_set<char> duplicate(temp.begin(),temp.end());
                if(temp.size()!=duplicate.size())
                    continue;
                res.push_back(temp);
                ans = max(ans,(int)temp.size());   
            }
        }  
        return ans;
    }
};

//using DP

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(string word:arr){
            bitset<26> bs_word(0);
            for(char c:word){
                bs_word.set(c-'a');
            }
            if(word.size()!=bs_word.count())
                continue;
            for(int i = 0;i<dp.size();i++){
                bitset bs_temp = dp[i];
                
                //checking that after merging would there be repeating charcter.
                if((bs_temp&bs_word).any())
                    continue;
                dp.push_back((bs_temp|bs_word));
                res = max(res,(int)(bs_temp.count())+(int)word.size());
            }    
        }
        return res;
    }
};