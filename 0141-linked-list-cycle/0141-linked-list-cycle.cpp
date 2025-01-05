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
    bool hasCycle(ListNode *head) {
        // TODO: Write your code here
        ListNode *s_ptr = head, *f_ptr = head;
        while (f_ptr != nullptr && (*f_ptr).next != nullptr){ //(*). is the same as dong ->
            s_ptr = s_ptr->next;
            f_ptr = f_ptr->next->next;
            if (f_ptr == s_ptr){
                return true;
            }
        }
        return false;
    }
};