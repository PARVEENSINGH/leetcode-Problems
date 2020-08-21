
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        
         int n=0;
        ListNode* ptr=head;
        int res=0;

        while(ptr!=NULL)
        {
            n++;
            ptr=ptr->next;
        }

        ptr=head;
        
        while(ptr!=NULL)
        {
            res+=pow(2,--n)*ptr->val;
            ptr=ptr->next;
        }

        return res;
    }
};