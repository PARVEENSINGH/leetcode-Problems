
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
  private:
    bool checkIntorNot(char ch)
    {
        if(ch=='0' || ch=='1' || ch=='2' ||
            ch=='3' || ch=='4' || ch=='5' || ch=='6' ||
            ch=='7' || ch=='8' || ch=='9')
            return true;
        else
            return false;          
    }
public:
    int myAtoi(string str) {
        
        int n=str.length(),mul=10;
        long long res=0;
        int ans=0;

        bool flag=true;

        for(int i=0;i<n;i++)
        {
            if(str[i]==' ')
                continue;
            else if(checkIntorNot(str[i]))
            {
                while(checkIntorNot(str[i]))
                    {
                        // check overflow
                        if(res*mul>INT32_MAX || res*mul<INT32_MIN  )
                            {
                                if(flag)
                                    return INT32_MAX;
                                else if(!flag) 
                                    return INT32_MIN;   
                            }
                            else   
                                res=res*mul+str[i]-'0';
                            i++;
                        } 
                        ans=res;
                        if(flag) 
                        {   //check overflow
                            if(res>INT32_MAX || res<INT32_MIN  )
                                return INT32_MAX;
                            return ans;
                        }
                        else if(!flag)
                        {   
                            //check overflow
                             if(res>INT32_MAX || res<INT32_MIN  )
                                return INT32_MIN;
                            return ans*-1; 
                        }
            }    
           
            else if( str[i]=='-' && i<n-1 && checkIntorNot(str[i+1]))
                flag=false;
            else if( str[i]=='+' && i<n-1 && checkIntorNot(str[i+1]))
                continue;   
            else
                return 0;
                
        }

        return res;
    }
};