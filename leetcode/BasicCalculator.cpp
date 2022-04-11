#include<bits/stdc++.h>
using namespace std;


// //https://leetcode.com/problems/basic-calculator/


// class Solution {
// public:
//     bool isDigit(char c){
//         if(c-'0'>=0 && c-'0'<=9)
//             return 1;
//         return 0;    
//     }

//     int evaluate(int a,int b,char op){
//         switch (op)
//         {
//         case '+': return a+b;
//         case '-': return a-b;
//         case '*': return a*b;
//         case '/': return a/b;
//         }
//         return 0;
//     }

//     int preference(char a){
//         if(a=='+' || a=='-')
//             return 1;
//         if(a=='*' || a=='/')
//             return 2;
//         return 0;        
//     }

//     int calculate(string s) {
//         int i = 0,n = s.length();
//         stack<char> op;
//         stack<int> val;
//         if(n==0)
//             return 0;
//         for(int i = 0;i<n;i++){
//             if(s[i]==' ')
//                 continue;
//             else if(isDigit(s[i])){
//                 int temp = 0;
//                 while(i<n && isDigit(s[i])){
//                     temp=temp*10+s[i]-'0';
//                     i++;
//                 }
//                 i--;
//                 val.push(temp);
//             }
//             else if(s[i]=='(')
//                 op.push(s[i]);
//             else if(s[i]==')'){
//                 char c=' ';
//                 while(!op.empty() && c!=')'){
//                     c = op.top();
//                     op.pop();
//                     int v1 = val.top();
//                     val.pop();
//                     int v2 = val.top();
//                     val.pop();
//                     val.push(evaluate(v1,v2,c));
//                 }
//             }  
//             else{
//                 //char c = ' ';
//                 while(!op.empty() && preference(op.top())>=preference(s[i])){
//                     int v1 = val.top();
//                     val.pop();
//                     int v2 = val.top();
//                     val.pop();
//                     val.push(evaluate(v1,v2,op.top()));
//                     op.pop();
//                 }
//                 op.push(s[i]);
//             }
//         }  
//         while (!op.empty()){
//             int v1 = val.top();
//             val.pop();
//             int v2 = val.top();
//             val.pop();
//             val.push(evaluate(v1,v2,op.top()));
//             op.pop();
//         }
//         return val.top();
//     }
// };



long long solve (int N, vector<int> cost, vector<vector<int> > edges) {
    vector<bool> vis(N,0);
   vector<vector<int>> graph(N);
   long long res = 0;
   for(int i = 0;i<N;i++){
       graph[edges[i][0]].push_back(edges[i][1]);
   } 
    for(int i = 0;i<N;i++){
        for(auto it = graph[i].begin();it!=graph[i].end();it++){
            cout<<i<<" : "<<graph[i][*it];
        }
        cout<<endl;
    }

   for(int i = 0;i<N;i++){
       if(!vis[i]){
            res+=cost[i];
            vis[i] = 1;
       }
       for(auto it = graph[i].begin();it!=graph[i].end();it++){
          if(cost[i] & cost[graph[i][*it]]){
              vis[graph[i][*it]] = 1;
          }
       }
   } 
   return res;
   
}












// class Solution {
// public:
//     int largestInteger(int num) {
//         int n = num;
//         vector<int> vec;
//         while(n){
//             vec.push_back(n%10);
//             n/=10;
//         }
//         reverse(vec.begin(),vec.end());
//         n = vec.size();
//         int res = 0;
//         int maxe = -1;
//         int ide = 0;
//         for(int i = 0;i<n;i++){
//             if(vec[i]%2==0)
//             { maxe = vec[i];
//                 for(int j = i;j<n;j++){
//                     if(vec[j]>maxe && vec[j]%2==0){
//                         maxe = vec[j];
//                         ide = j;
//                     }
//                 }
//                 int temp = vec[i];
//                 vec[i] = vec[ide];
//                 vec[ide] = temp;

//             }
//             else{
//                 maxe = vec[i];
//                 for(int j = i;j<n;j++){
//                     if(vec[j]>maxe && vec[j]%2)
//                         maxe = vec[j];
//                         ide = j;
//                 }
//                  int temp = vec[i];
//                 vec[i] = vec[ide];
//                 vec[ide] = temp;
//             }
//             maxe = res*10+maxe;
//             res = maxe;
//         }
//         return res;
//     }
// };


class Solution {
public:
    string minimizeResult(string s) {
        int i = 0;
        while(s[i]!='+'){
            i++;
        }
        int end1 = i;
        int end2 = s.length()-2;
        int st1 = 0;
        int st2 = i+1;

        int res = INT_MAX;
        for(int i = end1;i>=0;i--){
            int mul1 = 1;

            for(int j = st1;j<i;j++)
                mul1*=s[j]-'0';

            int a = 0;
            for(int a1 = i;a1<=end1;a1++) 
                a = a*10+s[a1]-'0';
            for(int a2 = st2;a2<end2;a2++){

                int mul2 = 1;
                for(int k = a2+1;k<end2;k++)
                    mul2*=s[k]-'0';

                int b = 0;
                for(int l = st2;l<=a2;l++) 
                   b= b*10+s[l]-'0'; 

                int sum = a+b;      
                int temp = mul1*sum*mul2;  
                res = min(temp,res); 
            }      
        }
        string ans = "";
        while(res){
            ans+=res%10;
            res/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};

// #define mod 1000000007
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums, int k) {
//         priority_queue<int,vector<int>, greater<int>> minHeap;
//         for(int i = 0;i<nums.size();i++)
//             minHeap.push(nums[i]);
//         while(k--){
//             int n = minHeap.top();
//             minHeap.pop();
//             n+=1;
//             minHeap.push(n);
//         }    

//         int res = 1;
//         while(!minHeap.empty()){
//             int n = minHeap.top();
//             minHeap.pop();
//             n%=mod;
//             res = (res*n)%mod;
//         }
//         return res%mod;
//     }
// };






























