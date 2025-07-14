class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            auto [node, currSum] = st.top();
            st.pop();

            // If it's a leaf node and sum matches
            if (node->left == nullptr && node->right == nullptr) {
                if (currSum == targetSum)
                    return true;
            }

            // Push children with updated path sums
            if (node->right)
                st.push({node->right, currSum + node->right->val});
            if (node->left)
                st.push({node->left, currSum + node->left->val});
        }

        return false;
    }
};
