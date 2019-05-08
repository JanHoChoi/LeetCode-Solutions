/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root != NULL)
            return max(maxDepth(root->left),maxDepth(root->right))+1;
        else return 0;        
    }
};
// BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res += 1;
            for(int i = 0, n = q.size(); i < n; i++){
                // 要用n表示size 因为中途由于插入会变
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
        }
        return res;
    }
};