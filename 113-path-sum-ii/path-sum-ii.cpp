/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *     right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;

    void helper(TreeNode* node, int targetSum, vector<int>& path, int currSum) {
        if (!node) return;

        path.push_back(node->val);
        currSum += node->val;

        // Check for leaf and valid path
        if (!node->left && !node->right && currSum == targetSum) {
            res.push_back(path);
        } else {
            helper(node->left, targetSum, path, currSum);
            helper(node->right, targetSum, path, currSum);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        helper(root, targetSum, path, 0);
        return res;
    }
};
