


#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* slptr=head;
        ListNode* fptr=head;
        //ListNode* fptr = list->next; -> Use this if we want to print the first node when there are two middle nodes.
        while(fptr!=NULL && fptr->next!=NULL)
        {
            slptr=slptr->next;
            fptr=fptr->next->next;
        }

        return slptr;
    }
};