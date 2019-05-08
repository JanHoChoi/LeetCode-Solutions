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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        return helper(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool helper(TreeNode * s, TreeNode * t){
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        return s->val == t->val && helper(s->left,t->left) && helper(s->right,t->right);
    }
};