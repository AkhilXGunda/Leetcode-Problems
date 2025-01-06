/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // O(n) time and O(1) space
    ListNode *detectCycle(ListNode *head) {
        // TODO: Write your code here
        pair<bool, ListNode *> cycle = isCycle(head);
        if (!cycle.first){
            return nullptr;
        }
        int len = cycleLength(head, cycle.second);
        ListNode *ptr1 = head, *ptr2 = head;
        for (int i = 0; i < len; i++){
            ptr2 = ptr2->next;
        }
        while (ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }

    pair<bool, ListNode *> isCycle(ListNode *head){
        ListNode *s = head, *f = head;
        while (f != nullptr && f->next != nullptr){
            s = s->next;
            f = f->next->next;
            if (s == f){
                return {true, s};
            }
        }
        return {false, s};
    }

    int cycleLength(ListNode *head, ListNode *ptr1){
        ListNode *ptr2 = ptr1;
        int len = 0;
        do{
            ptr2 = ptr2->next;
            len++;
        } while (ptr1 != ptr2);
        return len;
    }
};