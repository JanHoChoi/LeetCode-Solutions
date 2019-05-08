/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归方法
// class Solution {
// public:
//     int rangeSumBST(TreeNode* root, int L, int R) {
//         if(root == NULL)
//             return 0;
//         if(root->val > R)
//             return rangeSumBST(root->left, L, R);
//         if(root->val < L)
//             return rangeSumBST(root->right, L, R);
//         if(root->val == L)
//             return root->val + rangeSumBST(root->right,L,R);
//         else
//             return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
//     }
// };

// 迭代方法
#include<stack>
using namespace std;
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return 0; // 特殊情况
        stack<TreeNode*> s;
        TreeNode* cur = root;
        s.push(root);
        int res = 0;
        while(!s.empty()){
            cur = s.top();
            s.pop();
            if(cur!=NULL){
                if(cur->val >= L && cur->val <= R){
                    res += cur->val;
                }
                if(cur->val > L)
                    s.push(cur->left);
                if(cur->val < R)
                    s.push(cur->right);
            }         
        }
        return res;
    }
};

// 考察 二叉树 迭代/递归的遍历方法 没有要求什么顺序，所以迭代方法可以直接如上面解答这样写。