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
    void flatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        flattenHelper(root, prev);
    }

private:
    void flattenHelper(TreeNode* node, TreeNode*& prev) {
        if (!node) return;

        // Recur on right subtree first
        flattenHelper(node->right, prev);
        // Then recur on left subtree
        flattenHelper(node->left, prev);

        // Modify pointers
        node->right = prev;
        node->left = nullptr;

        // Move prev to current node
        prev = node;
    }
};
