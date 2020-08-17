#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/merge-k-sorted-lists/

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

    private:
    ListNode* Merge(ListNode* a,ListNode* b)
    {   
        ListNode* res=NULL;

        if(a==NULL)
            return b;
        if(b==NULL)
            return a;

        if(a->val<=b->val)
        {
            res=a;
            res->next=Merge(a->next,b);
        }        
        else
        {
            res=b;
            res->next=Merge(a,b->next);
        }
        return res; 
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* temp=NULL;
        int n=lists.size();
        
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];

        temp=Merge(lists[0],lists[1]);    

        for(int i=2;i<n;i++)
        {
            temp=Merge(temp,lists[i]);
        }

        return temp;
    }
};