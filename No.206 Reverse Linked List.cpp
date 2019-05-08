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
    // 递归
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * node = reverseList(head->next);
        head->next->next = head; // head->next已经变成了最后一个了
        head->next = NULL;
        return node;
    }

    // 迭代
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode * res = new ListNode(0);
        res->next = head;
        ListNode * cur = head;
        ListNode * temp;
        while(cur->next != NULL){
            temp = cur->next->next;
            cur->next->next = res->next;
            res->next = cur->next;
            cur->next = temp;
        }
        return res->next;
    }
};