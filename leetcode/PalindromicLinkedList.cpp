#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/palindrome-linked-list/

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

//Using extra space;
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp){
            if(st.top()!=temp->val)
                return false;
            st.pop();
            temp=temp->next;
        }
        return true;
    }
};


//Without extra space

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* temp = head,*curr = head,*prev = NULL;
        while(temp){
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }

    bool CompareBothPart(ListNode* list1,ListNode*  list2){
        if(!list1 && !list2)
            return 1;
        while(list1 && list2){
            if(list1->val!=list2->val)
                return false;
            list1 = list1->next;
            list2 = list2->next;
        } 
        return true;   
    }

    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode*  slptr = head,*fptr = head,*prev_of_slptr = NULL;
        ListNode* midnode = NULL,*secondPart=NULL;

        if(!head)
            return false;
        if(head->next==NULL){
            return true;
        }
        while(fptr && fptr->next){
            prev_of_slptr = slptr;
            slptr = slptr->next;
            fptr = fptr->next->next;
        }    

    /* fast_ptr would become NULL when there are even elements in list.
        And not NULL for odd elements. We need to skip the middle node
        for odd case and store it somewhere so that we can restore the
        original list*/
        if(fptr){
            midnode = slptr;
            slptr = slptr->next;
        }

        prev_of_slptr->next = NULL;
       
        secondPart = reverse(slptr);
        bool res = CompareBothPart(head,secondPart);

        //Revert the list in actual or real form
       
        ListNode* link = reverse(secondPart);
      
        if(midnode){
            prev_of_slptr->next = midnode;
            midnode->next = link;
           
        }else
            prev_of_slptr->next = link;
        return res;    
    }
};
