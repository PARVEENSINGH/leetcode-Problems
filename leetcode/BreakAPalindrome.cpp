#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int cnta=0,idx;
        int n = palindrome.size();
        if(n==1)
            return "";
        for(char c :palindrome)
            if(c=='a')
                cnta++;
        if(cnta==n){
            palindrome[n-1]+=1;
            return palindrome;
        }
        if(n%2!=0)
             idx = (n/2);
        for(int i = 0;i<n;i++){
            if(i!=idx && palindrome[i]!='a' ){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};