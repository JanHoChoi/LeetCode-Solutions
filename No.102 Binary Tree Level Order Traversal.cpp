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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        int level = 0;
        TreeNode* cur = root;
        queue<TreeNode*> q;
        q.push(cur);
        q.push(NULL); // 用NULL作标记
        vector<int> row;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                res.push_back(row);
                // 这一层已经没了
                row.clear();
                if(q.size()>0){
                    q.push(NULL); // 再放一个标记
                    continue;
                }
                else
                    break;
            }
            row.push_back(temp->val);
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        return res;
    }
};