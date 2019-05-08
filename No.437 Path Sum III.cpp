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
    // pathSum表示从root开始，不一定选root。
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        return pathSum(root->left,sum) + pathSum(root->right,sum) + pathStart(root,0,sum);
    }
    // pathStart表示之前已经选了很多点，现在到了root的位置，所以root也要选
    int pathStart(TreeNode * root, int before, int target){
        if(root == NULL)
            return 0;
        int current = before + root->val;     
        return (current == target) + pathStart(root->left, current, target) 
        + pathStart(root->right, current, target);

    }
};