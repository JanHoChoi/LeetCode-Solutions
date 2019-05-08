/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * head_copy = nullptr, * cur = head, * cur_copy = nullptr;
        if (head == nullptr)
            return nullptr;

        // 第一个循环把1-2-3-4...变成1-1-2-2-3-3-4-4...
        while(cur){
            cur_copy = new Node(cur->val, cur->next, nullptr); // 拷贝一个一样的节点
            cur->next = cur_copy; // 把拷贝的节点放在正常节点后面
            cur = cur_copy->next;
        }
        
        // 第二个循环 把拷贝的节点的随机节点分配好
        cur = head;
        while(cur){
            cur_copy = cur->next; // 此时cur->next刚好是拷贝的新节点
            if(cur->random){ // cur->random->next也是拷贝的cur->random
                cur_copy->random = cur->random->next;
            }
            cur = cur_copy->next;
        }

        // 第三个循环 把拷贝节点与原节点的连接断开
        cur = head;
        head_copy = head->next;
        while(cur){
            cur_copy = cur->next;
            cur->next = cur_copy->next; // 还原原来的连接
            if(cur->next)
                cur_copy->next = cur->next->next;
            cur = cur->next;
        }
        return head_copy;
    }
};