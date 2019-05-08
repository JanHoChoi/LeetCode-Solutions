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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     TreeNode* cur = root;
    //     stack<TreeNode*> s;
    //     while(!s.empty() || cur != NULL){
    //         if(cur==NULL){
    //             cur = s.top();
    //             s.pop();
    //             res.push_back(cur->val);
    //             cur = cur->right;
    //         }
    //         else{
    //             s.push(cur);
    //             cur=cur->left;
    //         }
    //     }
    //     return res;
    // }
    
    // 递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(),left.begin(),left.end());
        res.push_back(root->val);
        res.insert(res.end(),right.begin(),right.end());
        return res;
    }
};