/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        TreeNode * pre = root;
        if(root->right) s.push(root->right);
        if(root->left) s.push(root->left);
        root->left = NULL;
        while(!s.empty()){
            TreeNode* cur = s.top(); // 前序遍历的思想
            s.pop();
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left); // 要先压右，再压左。这样左才会先出栈
            pre->right = cur;
            cur->left = NULL;
            pre = cur;
        }
        return;
    }
};