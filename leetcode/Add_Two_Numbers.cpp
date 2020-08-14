#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;



//https://leetcode.com/problems/add-two-numbers/



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int k=0,sum=0;
        
        k+=l1->val+l2->val;
        sum=k;
        k/=10;
        
        ListNode* temp=new ListNode(sum%10);
        ListNode* res=temp;
        
        l1=l1->next;
        l2=l2->next;
        
        
        while(l1!=NULL || l2!=NULL)
        {
            
            if(l1!=NULL && l2!=NULL)
            {
                k+=l1->val+l2->val;
                sum=k;
                k/=10;
                
                res->next=new ListNode(sum%10);
                res=res->next;
                
                l1=l1->next;
                l2=l2->next;
            }
            
            else if(l1!=NULL && l2==NULL)
            {
                 k+=l1->val;
                 sum=k;
                 k/=10;
                
                 res->next=new ListNode(sum%10);
                 res=res->next;
                
                 l1=l1->next; 
            }
            
            else if(l1==NULL && l2!=NULL)
            {
                k+=l2->val;
                sum=k;
                k/=10;
                
                res->next=new ListNode(sum%10);
                res=res->next;
                
                l2=l2->next;
            }
             
        }
        
        if(k)
            res->next=new ListNode(k);
        
       return temp; 
       
    }
};