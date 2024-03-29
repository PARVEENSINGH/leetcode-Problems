#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        int a0 = 0;
        int a1 = 1;
        int a2 = 1;
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
       
        int temp;
        for(int i = 0;i<=n-3;i++){
            temp = a2 + a1 + a0;
            a0 = a1;
            a1 = a2;
            a2 = temp;
        }
        return a2;
    }
};