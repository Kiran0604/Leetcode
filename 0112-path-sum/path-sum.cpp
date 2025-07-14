class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        // If it's a leaf node, check if the path sum matches
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;

        // Recur on left and right subtrees with reduced target sum
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
