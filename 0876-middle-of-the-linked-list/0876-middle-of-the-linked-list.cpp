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
    ListNode* middleNode(ListNode* head) {
        //O(n) time O(1) space
        // TODO: Write your code here
        ListNode *s = head;
        int num = 0;
        while (s != nullptr){
            num++;
            s = s->next;
        }
        num = num/2;
        s = head;
        for (int i = 0; i < num; i++){
            s = s->next;
        }
        return s;
    }
};