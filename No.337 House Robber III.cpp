/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 对任意根节点来说，f1(x)=可以偷x本身情况下，最大的值（也可以不偷）；f2(x)=不能偷x的情况下，最大的值。
// f1(x) = max[(f2(x->left) + f2(x->right) + x->val), f2(x)]
// f2(x) = f1(x->left) + f1(x->right)
// 对于root为根节点来说，取max(f1(root),f2(root)).
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int,int> res = helper(root);
        return res.first;
    }
    pair<int,int> helper(TreeNode* root){
        if(root == NULL)
            return make_pair(0,0);
        pair<int,int> left = helper(root->left);
        pair<int,int> right = helper(root->right);
        int f2 = left.first + right.first;
        int f1 = max(left.second+right.second+root->val,f2);
        return make_pair(f1,f2);
    }
};