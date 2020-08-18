
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/regular-expression-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        
         
        int m=s.length();
        int n=p.length();

        bool res[m+1][n+1];

        for(int i=0;i<=m;i++)
            res[i][0]=false;

        for(int i=0;i<=n;i++)
            res[0][i]=false;

        res[0][0]=true;
        
        // It is include to handle the cases a* or a*b* & so on.
        //eg. s=" " p="a*" If would not provide the below initilization then it would generate the false result
        // which is incorrect. So, to get correct result in these situations it is included.
         for(int i=1;i<=n;i++)
             if(p[i-1]=='*')
               res[0][i]=res[0][i-2];
        
      
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //if corresponding characters matches
                if(s[i-1]==p[j-1] || p[j-1]=='.')
                    res[i][j]=res[i-1][j-1];

                else if(p[j-1]=='*')
                {
                    // If we consider zero occurance of the character followed by *
                    res[i][j]=res[i][j-2];
                    
                    //It might be the case that when considering the zero occurances match not possible 
                    // Hence checking other possibility to consider one or more occurances of the characters
                    // p[j-2]=='.' if * follows '.' then the expression can be matched.
                    //p[j-2]==s[i-1] it checks that if we would consider the zero occurances  then it can be checked
                    //that the pattern matched to just previous state or upto p[j-2].

                    //In another words if any of these condition matched then we are more likely 
                    // to get a match otherwise the above value would be final for table entry
                    
                    if(p[j-2]=='.' || p[j-2]==s[i-1])
                        res[i][j]=res[i][j-2] || res[i-1][j];
                    
                }  

                else
                    res[i][j]=false;
                  
            }
        } 

        return res[m][n];    
    }
};