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
    // 迭代
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q1,q2;
        TreeNode * left, * right;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if(left != NULL && right != NULL){
                if(left->val != right->val){
                    return false;
                }
                else{
                    q1.push(left->left);
                    q1.push(left->right);
                    q2.push(right->right);
                    q2.push(right->left);
                }
            }
            else if(left == NULL && right == NULL)
                continue;
            else
                return false;
        }
        return true;
    }
};