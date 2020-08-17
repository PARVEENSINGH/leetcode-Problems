
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* ans=head;
        ListNode* prev=head;
        ListNode* temp=head;
        
       
        while(n--)
            temp=temp->next;
   
     if(temp==NULL)
        {
             prev=prev->next;
             ans=prev;
             return ans;
        }
        
      
        while(temp->next!=NULL)
        {
            temp=temp->next;
            prev=prev->next;
        }

        prev->next=prev->next->next;

        return ans;
    }
};