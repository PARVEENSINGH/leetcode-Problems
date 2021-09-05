// class Solution {
// public:
//     bool isPalindrome(int x) {
//         int div =   1;
//         x = x<0 ? x*-1:x;
//         int num = x;
//         int lead,trail;
//         while(x / div >= 10)
//             div *= 10;
//         while(x!=0){
//             lead = x/div;
//             trail = x/10;
//             if(lead!=trail)
//                 return false;
//             x = (x % div)/10;
//             div/=100;    
//         }    
//         return true;
//     }
// };


//faster

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0))
            return false;
        int sum = 0;
        int mul = 10;    
        while(x>sum){
            sum = sum*mul + x%10;
            x /= 10;
        }    
        return (x==sum) || (x==sum/10);  //s==sum if digits are even , sum/10 if digits are odd.
    }
};