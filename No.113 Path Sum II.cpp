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

    void helper(vector<vector<int> > & res, vector<int> & solution, TreeNode* root, int sum){
        if(!root->left && !root->right){
            // 如果是叶子节点
            if(sum == 0){
                res.push_back(solution);
            }
        }
        if(root->left){
            solution.push_back(root->left->val);
            helper(res,solution,root->left,sum-root->left->val);
            solution.pop_back(); // 把左节点的pop出来
        }

        if(root->right){
            solution.push_back(root->right->val);
            helper(res,solution,root->right,sum-root->right->val);
            solution.pop_back();
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> solution;
        solution.push_back(root->val); // 已算上本身
        helper(res,solution,root,sum-root->val);
        return res;
    }
};