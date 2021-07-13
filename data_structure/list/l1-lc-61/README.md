## Solutions
```c++
// problem name: Rotate List
// problem link: https://leetcode.com/problems/rotate-list/
// contest link: (?)
// time: (?)
// author: pri1311


// other_tags: (?)
// difficulty_level: beginner


/**
 * meta:
 *   - input: head = [1,2,3,4,5], k = 2
 *   - output: [4,5,1,2,3]
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        if (count == 0 || k == 0 || count == 1 || k % count == 0 ) return head;
        count -= (k%count);
        temp = head;
        ListNode * q = NULL;
        while (count--){
            q = temp;
            temp = temp->next;
        }
        q->next = NULL;
        ListNode * p;
        p = temp;
        while (temp->next && temp){
            temp = temp->next;
        }
        temp->next = head;
        return p;
    }
};

```
