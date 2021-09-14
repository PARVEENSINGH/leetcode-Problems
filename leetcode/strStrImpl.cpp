#include<bits/stdc++.h>
using namespace std;
//Using KMP Algorithm
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle=="")
//             return 0;
//         int m = needle.length();
//         int n = haystack.length();
//         if(n<m)
//             return -1;
//         int j =0, i =0,res = 0;
//         for(i = 0;i<n;i++){
//             if(j==m)
//                 return i-j;
//             else if(haystack[i]==needle[j]){
//                 j++;
//             }
//             else{
//                 if(j>0)
//                     i-=j;
//                 j = 0;    
//             }
                
//         }
        
//        return j<m?-1:i-j; 
//     }
// };

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        int m = needle.length();
        int n = haystack.length();
        if(n<m)
            return -1;
        
        for(int i = 0;i<n-m+1;i++)
            if(haystack.substr(i, m)==needle)
                return i;
        return -1;        
    }
};