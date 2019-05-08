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
        if(!head || !head->next) return head; // 只有0/1个节点直接return
        
        ListNode res(0);
        res.next = head;
        ListNode * cur = &res; // cur是比较的两个节点的父亲。     
        while(cur->next && cur->next->next){
            if(cur->next->val == cur->next->next->val){
                int dupli = cur->next->val;
                while(cur->next && cur->next->val == dupli)
                    cur->next = cur->next->next; 
                // 出循环时, cur->next一定和dupli不同(要么为NULL要么为新值)
                // 相当于把原来相同的节点删去了
            }
            else{
                cur = cur->next; // 只改变cur 不改变cur->next
            }
        }
        return res.next;
    }
};