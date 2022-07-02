/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int res;
    // 后序遍历
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftDepth = diameterOfBinaryTree(root->left);
        int rightDepth = diameterOfBinaryTree(root->right);
        res = std::max(res, leftDepth + rightDepth);
        return std::max(leftDepth, rightDepth) + 1; // 左右子树最深深度
    }
};
// @lc code=end
