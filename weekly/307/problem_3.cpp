// BFS

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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> g;
        traverse(root, g, nullptr);
        int n = g.size();
        unordered_map<int, bool> visit;
        for(auto kv : g)
            visit[kv.first] = false;
        visit[start] = true;
        vector<vector<int>> ans;
        queue<int> q{{start}};
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++) {
                auto t = q.front();
                q.pop();
                for(auto u : g[t]) {
                    if(!visit[u]) {
                        q.push(u);
                        tmp.push_back(u);
                        visit[u] = true;
                    }
                }
            }
            ans.push_back(tmp);
        }
        return ans.size() - 1;
    }


private:
    void traverse(TreeNode *root, unordered_map<int, vector<int>> &g, TreeNode *p) {
        if(!root)
            return;
        if(p)
            g[root->val].push_back(p->val);
        if(root->left)
            g[root->val].push_back(root->left->val);
        if(root->right)
            g[root->val].push_back(root->right->val);
        traverse(root->left, g, root);
        traverse(root->right, g, root);
    }
};
