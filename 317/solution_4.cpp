// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/discuss/2758013/Level-%2B-Depth
// level + depth

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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;
        traverse(root, 0);
        for(int q : queries) {
            int level = node_level[q], depth = node_depth[q];
            auto &ld = level_depth[level];
            if(*rbegin(ld) == depth)
                depth = ld.size() == 1 ? 0 : *next(rbegin(ld));
            else
                depth = *rbegin(ld);
            ans.push_back(level + depth - 1);
        }
        return ans;
    }
    
private:
    unordered_map<int, int> node_level, node_depth;
    unordered_map<int, multiset<int>> level_depth;
    
    int traverse(TreeNode *n, int level = 0) {
        if(!n)
            return 0;
        int depth = 1 + max(traverse(n->left, level + 1), traverse(n->right, level + 1));
        node_level[n->val] = level;
        node_depth[n->val] = depth;
        level_depth[level].insert(depth);
        return depth;
    }
};
