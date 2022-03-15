#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/decode-ways/

//Recursive Solution or BruteForce

//Would give TLE
class Solution {
public:

    int DecodeWays(int i,string s){
        if(i>=s.length())
            return 1; //base case
        int ans = 0;
        int TenthPlace = s[i]-'0',TwodigitNum = 0;    
        if(i<s.length()-1)
            TwodigitNum = TenthPlace*10+s[i+1]-'0'; //Generating two digit number to check it belongs to [10,26]
        if(TenthPlace>0)
            ans+= DecodeWays(i+1,s); //one digit taken as the root of tree being generating
        if(TenthPlace>0 && TwodigitNum>=10 && TwodigitNum<=26) 
             ans+= DecodeWays(i+2,s);   //one digit & twodigit num both counted as two branch of tree started    
        return ans;    
    }
    int numDecodings(string s) {
       return DecodeWays(0,s);
    }
};


//Use Memoization

class Solution {
public:

    int DecodeWays(int i,string s,vector<int> &dp){
        if(i>=s.length())
            return 1; //base case
        if(dp[i]!=-1)
            return dp[i];    
        int ans = 0;
        int TenthPlace = s[i]-'0',TwodigitNum = 0;    
        if(i<s.length()-1)
            TwodigitNum = TenthPlace*10+s[i+1]-'0'; //Generating two digit number to check it belongs to [10,26]
        if(TenthPlace>0)
            ans+= DecodeWays(i+1,s,dp); //one digit taken as the root of tree being generating
        if(TenthPlace>0 && TwodigitNum>=10 && TwodigitNum<=26) 
             ans+= DecodeWays(i+2,s,dp);   //one digit & twodigit num both counted as two branch of tree started    
        return dp[i] = ans;    
    }
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,-1);
       return DecodeWays(0,s,dp);
    }
};

//Converting Memoization into dp or Bottomup approach

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+2,0);
        int n = s.length();
        dp[n+1] = 1;
        dp[n] = 1;
        int TenthPlace = 0,TwodigitNum = 0;  
        for(int i = n-1;i>=0;i--){
            TenthPlace = s[i]-'0';
            if(i<s.length()-1)
                TwodigitNum = TenthPlace*10+s[i+1]-'0';
            if(TenthPlace>0)
                dp[i]+=dp[i+1];
            if(TenthPlace>0 && TwodigitNum>=10 && TwodigitNum<=26) 
                dp[i]+=dp[i+2];     
        }
       return dp[0];
    }
};

