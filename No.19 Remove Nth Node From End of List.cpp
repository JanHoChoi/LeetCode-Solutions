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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast = head;
        int count = 0;
        while(fast && count < n){
            fast = fast->next;
            count += 1;
        }
        if(count < n)
            return head; // 没有倒数第K个 没得删

        ListNode temp(0);
        temp.next = head;
        ListNode * slow = &temp;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode * toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;
        return temp.next;
    }
};