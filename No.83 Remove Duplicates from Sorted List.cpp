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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode * first = head, * second = head->next;
        while(second != NULL){
            if(first->val == second->val){
                first->next = second->next;
                second = first->next;
                continue;
            }
            first = first->next;
            second = first->next;
        }
        return head;
    }
};