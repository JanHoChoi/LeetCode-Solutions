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
    TreeNode * helper(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pl >= pr) return nullptr;
        TreeNode * root = new TreeNode(preorder[pl]);
        // 找到根节点在中序的位置 计算出左子树有多长
        int left_length = find(inorder.begin()+il,inorder.begin()+ir,preorder[pl]) - inorder.begin() - il;

        root->left = helper(preorder,pl+1,pl+1+left_length,inorder,il,il+left_length);
        root->right = helper(preorder,pl+1+left_length,pr,inorder,il+1+left_length,ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};