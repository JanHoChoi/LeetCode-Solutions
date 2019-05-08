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
    int maxPath = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        if(maxPath > 0)
            return this->maxPath-1;
        else
            return 0;
    }
    int dfs(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        this->maxPath = max(this->maxPath, left+right+1);
        return max(left,right)+1;
    }
};