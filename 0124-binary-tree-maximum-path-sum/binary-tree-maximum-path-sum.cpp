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
    int maxSum = INT_MIN;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        // Only consider positive contributions from left and right
        int left = max(0, dfs(node->left));
        int right = max(0, dfs(node->right));

        // Calculate the path sum through the current node
        int currentPathSum = node->val + left + right;

        // Update the global max if the current path sum is higher
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum gain to be used by parent node
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
