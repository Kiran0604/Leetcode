class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
    vector<int> path;
    int level = log2(label); // find the level of the label

    while (label >= 1) {
        path.push_back(label);

        int level_start = pow(2, level);
        int level_end = pow(2, level + 1) - 1;

        // Find the label's parent in a normal binary tree,
        // then mirror it for zigzag level if necessary
        label = (level_start + level_end - label) / 2;

        level--;
    }

    reverse(path.begin(), path.end());
    return path;
}
};