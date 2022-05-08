// recursive

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
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }

private:
    int ans;

    // {sum, cnt}
    pair<int, int> helper(TreeNode *root) {
        if(!root) return {0, 0};
        auto [a, b] = helper(root->left);
        auto [c, d] = helper(root->right);
        int sum = root->val + a + c;
        int cnt = 1 + b + d;
        if(root->val == (sum / cnt))
            ans++;
        return {sum, cnt};
    }
};
