/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 迭代做法
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 特殊情况判断:根节点即为空
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        TreeNode* res = t1;
        stack<TreeNode*> s1,s2;
        s1.push(t1);
        s2.push(t2);
        while(!s1.empty()){
            TreeNode *x1 = s1.top(), *x2 = s2.top();
            s1.pop();
            s2.pop();
            x1->val += x2->val;
            if(x1->left == NULL && x2->left != NULL)
                x1->left = x2->left;
            else if(x1->left != NULL && x2->left != NULL){
                s1.push(x1->left);
                s2.push(x2->left);
            }
            if(x1->right == NULL && x2->right != NULL)
                x1->right = x2->right;
            else if(x1->right != NULL && x2->right != NULL){
                s1.push(x1->right);
                s2.push(x2->right);
            }
        }
        return res;
    }
};

// 要点是：如果其中一边的左(右)节点为空，另一边的不为空，可以直接赋值，省略了进栈的操作


// 递归做法
// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//         // 特殊情况判断:根节点即为空
//         if(t1 == NULL)
//             return t2;
//         if(t2 == NULL)
//             return t1;
//         TreeNode* res = new TreeNode(t1->val+t2->val);
//         res->left = mergeTrees(t1->left,t2->left);
//         res->right = mergeTrees(t1->right,t2->right);
//         return res;
//     }
// };