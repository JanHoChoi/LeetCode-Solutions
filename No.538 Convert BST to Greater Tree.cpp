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
    // 迭代 思路类似先遍历右子树 再遍历中间 再遍历左子树
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int sum = 0;
        while(!s.empty() || cur != NULL){
            if(cur != NULL){
                s.push(cur);
                cur = cur->right;
            }
            else{
                TreeNode* temp = s.top();
                s.pop();
                temp->val += sum;
                sum = temp->val;
                cur = temp->left;
            }
        }
        return root;
    }

    int sum = 0;
    // 递归
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }

    void helper(TreeNode* cur){
        if(cur->right != NULL)
            helper(cur->right);
        sum += cur->val; 
        cur->val = sum;
        if(cur->left != NULL)
            helper(cur->left);
    }
};