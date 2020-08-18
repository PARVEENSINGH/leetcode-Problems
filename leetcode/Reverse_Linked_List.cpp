
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
      
        
          if(head==NULL)
            return NULL;

         ListNode* prev=NULL;
         ListNode* ptr=head;
         ListNode* temp=head;

          while(ptr!=NULL)
          {
              temp=ptr->next;
              ptr->next=prev;
              prev=ptr;
              ptr=temp;
             
          }
        return prev;  
    }
};