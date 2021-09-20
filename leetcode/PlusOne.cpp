
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
           int n = digits.size()-1;
           vector<int> res(n+2);
        if(digits[n]<9)
            digits[n]+=1;
        else{
            while(n>=0 && digits[n]==9){
                digits[n] = (digits[n]+1)%10;
                n--;
            }
            if(n==-1){
               
                res[0] = 1;
                return res;
            }
            else
                digits[n]+=1;    
        }
        return digits;
    }
};