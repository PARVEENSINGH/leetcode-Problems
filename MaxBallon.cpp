#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int a[26] = {0};
    int maxNumberOfBalloons(string text) {
        int i =0,n = text.length();
        int res = n;
        while(text[i]){
            if(text[i] == 'b' || text[i] == 'a' || text[i] =='l'
            || text[i] == 'o' || text[i] == 'n')
                a[text[i]-'a']+=1;
            i++;
        }
        if(a['b'-'a']==0 || a[0] == 0 || a['l'-'a']<2
        || a['o'-'a']<2 || a['n'-'a']==0)
            return 0;
        else{   
             a['l'-'a']/=2;
             a['o'-'a']/=2; 
             for(i = 0;i<26;i++){
                if(a[i]!=0 && a[i]<res)
                    res = a[i];
             }
        }
        return res;        
    }
};