#include<bits/stdc++.h>
using namespace std;
static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();
class Solution {
public:

typedef struct SlowestKey
{
    int duration;
    char key;

    SlowestKey(int duration,char key):duration(duration),key(key){

    }
}SlowestKey;
struct comparator{
 bool operator() (const SlowestKey &s1, const SlowestKey &s2){
        if(s1.duration==s2.duration){
            return s1.key<s2.key;
        }
       return s1.duration<s2.duration;
    }
};
    priority_queue<SlowestKey, vector<SlowestKey>, comparator> pq;
    
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        //SlowestKey s;
        // s.duration = releaseTimes[0];
        // s.key = keysPressed[0];
        pq.push(SlowestKey(releaseTimes[0],keysPressed[0]));
        for(int i = 1;i<n;i++){
            // s.duration = releaseTimes[i]-releaseTimes[i-1];
            // s.key  = keysPressed[i];
            pq.push(SlowestKey(releaseTimes[i]-releaseTimes[i-1],keysPressed[i]));
        }

        return  pq.top().key;
    }
};