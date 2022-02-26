#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Also can be solved using visiting array or Hashing


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* slptr = head;
        ListNode* fptr = head;
        while(slptr && fptr && fptr->next){
            slptr = slptr->next;
            fptr = fptr->next->next;
        }
        if(slptr == fptr)
            return true;
        return false;        
    }
};