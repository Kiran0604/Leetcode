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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;

        q.push({root, 0});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (res.size() == level)
                res.push_back({});

            if (level % 2 == 0)
                res[level].push_back(node->val);      // left to right
            else
                res[level].insert(res[level].begin(), node->val); // right to left

            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }

        return res;
    }
};
