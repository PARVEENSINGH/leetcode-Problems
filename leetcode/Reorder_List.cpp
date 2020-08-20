
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/reorder-list/

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
    void Merge(ListNode* list1,ListNode* list2)
    {
        ListNode* ref_list1=NULL;
        ListNode* ref_list2=NULL;
       
        while(list1!=NULL )
        {
            ref_list1=list1->next;
            ref_list2=list2->next;
            
            list1->next=list2;
            
            //It is included when the nodes are odd. Then ref_list1 or list1->next becomes NULL. so
            // in that case we have to prevent the last element present in list2 from deletion. Hence we have to exit & the 
            //remaining list2 with 2 elements would be appaneded to list1.
            
            if(ref_list1==NULL)
                break;
            
            list2->next=ref_list1;
            list2=ref_list2;
            list1=ref_list1;
        }
    }
    
    ListNode* reverseList(ListNode* list2)
   {
       ListNode* prev=NULL;
       ListNode* ptr=list2;
        ListNode* temp=list2; 

        while(ptr!=NULL)
        {
            temp=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=temp;
        }

    return prev;
   }
public:
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return;
        ListNode* list1=head;
        ListNode* list2=head;
        ListNode* slptr=head;
        ListNode* fptr=head;
        ListNode* endlist1=NULL;
       

        while(fptr!=NULL && fptr->next!=NULL)
        {
            endlist1=slptr;
            slptr=slptr->next;
            fptr=fptr->next->next;
        }

        list2=slptr;
        endlist1->next=NULL;
       
        Merge(list1,reverseList(list2));

        /*Better Solution using vector

         void reorderList(ListNode* head) {
                
        if(head==NULL || head->next==NULL)
            return;
        
        ListNode* list1=head;
       
        vector<ListNode*> container;

        while(list1!=NULL)
        {
            container.push_back(list1);
            list1=list1->next;
        }

        int i=0;
        int n=container.size()-1;

        while(i<n)
        {
            container[n]->next=container[i]->next;
            container[i]->next=container[n];
            i=i+1;
            n=n-1;
        }
        container[i]->next=NULL;*/
    }
    }
};