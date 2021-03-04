// problem name: Remove Nth Node From End of List
// problem link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// contest link: (?)
// time: (?)
// author: pri1311


// other_tags: (?)
// difficulty_level: easy


/**
 * meta:
 *   - short_problem_description: Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *   - follow_up: Could you do this in one pass?
 */

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
        int count=0;
        ListNode*p=head;
        while(p){
            count++;
            p=p->next;
        }
        if (count==1){
            delete p;
            return NULL;
        }
        p=head;
        int i=count-n-1;
        if (n==count){
            head=head->next;
            delete p;
            return head;
        }
        while(i--){
            p=p->next;
        }
        ListNode*t=p->next;
        p->next=t->next;
        delete t;
        return head;
    }
};
