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
    // 递归
    bool hasPathSum(TreeNode* root, int sum){
        if(!root) return false;
        if(root && !root->left && !root->right){ // 如果是叶子节点
            return sum-root->val == 0;
        }
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right, sum-root->val);
    }

    // dfs with stack
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        stack< pair<TreeNode*, int> > s;
        s.push(make_pair(root,0));
        int _sum = 0;
        pair<TreeNode*,int> cur;
        while(!s.empty()){
            cur = s.top();
            s.pop();
            if(!cur.first->left && !cur.first->right){
                if(cur.second + cur.first->val == sum)
                    return true;
            }
            if(cur.first->right)
                s.push(make_pair(cur.first->right,cur.second+cur.first->val));
            if(cur.first->left)
                s.push(make_pair(cur.first->left,cur.second+cur.first->val));
        }
        return false;
    }

    // bfs with queue
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        queue< pair<TreeNode*, int> > s;
        s.push(make_pair(root,0));
        int _sum = 0;
        pair<TreeNode*,int> cur;
        while(!s.empty()){
            cur = s.front();
            s.pop();
            if(!cur.first->left && !cur.first->right){
                if(cur.second + cur.first->val == sum)
                    return true;
            }
            if(cur.first->right)
                s.push(make_pair(cur.first->right,cur.second+cur.first->val));
            if(cur.first->left)
                s.push(make_pair(cur.first->left,cur.second+cur.first->val));
        }
        return false;
    }
};