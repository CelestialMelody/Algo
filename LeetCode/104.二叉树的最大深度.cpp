/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int curDepth;
    // 先序遍历，访问最深的层数
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        curDepth++;
        res = std::max(res, curDepth);
        maxDepth(root->left);
        maxDepth(root->right);
        curDepth--;
        return res;
    }
    // 后序遍历，左右最深+1
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return std::max(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end
