
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    
    ListNode* reverseLinkedList(ListNode* head,int k,int n)
    {
         ListNode* ptr=head;
         ListNode* prev=NULL;
         ListNode* temp=head;
         int a=k;
       
         while(n && ptr!=NULL && a--)
         {
             temp=ptr->next;
             ptr->next=prev;
             prev=ptr;
             ptr=temp;
         }

         if(n && temp!=NULL)
            head->next=reverseLinkedList(temp,k,n-1);

        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
            if(head==NULL)
                return NULL;

            ListNode* ptr=head;
            ListNode* prev=NULL;
            ListNode* res=NULL;
    
            int len=0;

            // Calulating length
            while(ptr!=NULL)
            {
                len++;
                ptr=ptr->next;
            }
        
            ptr=head;
            int n=len/k;
        
            int a=n*k;  

            //getting the pointer to the location from where the length upto end is less than k
            while(a--)
                ptr=ptr->next;
        
        //If the length of list is not a multiple of k
            if(len%k!=0)
            {
                prev= reverseLinkedList(head,k,n);
                res=prev;
                
                //iterating to get the pointer to the location where the remaining elements cab be appaended.
                while(prev->next!=NULL)
                    prev=prev->next;
                
                prev->next=ptr;
                
                return res;
            }
       //If list length is multiple of k
        return reverseLinkedList(head,k,n);    
    }
};