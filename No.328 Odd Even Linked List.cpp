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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode temp(-1);
        temp.next = head;
        ListNode * lastOdd = &temp;
        ListNode * cur = &temp;
        while(cur->next){
            cout << cur->next->val;
            if(cur->next->val % 2){
                // 如果是奇数
                if(lastOdd != cur){
                    // 操作
                    ListNode* t = lastOdd->next;
                    lastOdd->next = cur->next;
                    cur->next = cur->next->next;
                    lastOdd->next->next = t;
                    lastOdd = lastOdd->next;
                }
            }
            cur = cur->next;
        }
        return temp.next;
    }
};