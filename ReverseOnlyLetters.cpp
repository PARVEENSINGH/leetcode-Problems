class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length()-1;
        int i = 0;
        while(i<=n){
            if(((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)) && 
            ((s[n]>=65 && s[n]<=90) || (s[n]>=97 && s[n]<=122))){
                swap(s[i],s[n]);i++;n--;
            }
            else if(!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))) {
                i++;
                
            }
            else if(!((s[n]>=65 && s[n]<=90) || (s[n]>=97 && s[n]<=122)))    {
                
           
                n--;
            }
            else{
                i++;
                n--;
            }       
            
        }
        return s;
    }
};

