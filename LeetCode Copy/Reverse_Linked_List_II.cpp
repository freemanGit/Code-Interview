/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//1. find node before starting rotation position
//2. rotate: pre, curr, next 
//3. combine list
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(!head) return NULL;
        if(n-m == 0) return head;
        
        
        ListNode* dummy = new ListNode(-1); //create dummy node to handle head node
        dummy -> next = head;
        ListNode* pre = dummy;
        ListNode* curr = head;
        
        int i = m;  //do not change m
        while(i-1 > 0)
        {
            pre = curr;
            curr = curr->next;
            i--;
        }
        
        ListNode* st = curr;
        ListNode* pree = NULL;
        while (n -m >=0)  //loop times
        {
            ListNode* next = curr->next;
            curr->next = pree;
            pree = curr;
            curr = next;
            n--;
        }
        pre->next = pree;
        st->next = curr;
        
        return dummy->next;
    }
};