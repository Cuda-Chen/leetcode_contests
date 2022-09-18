// level order traversal

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> arr;
        queue<TreeNode *> q{{root}};
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp;
            while(size--) {
                auto *t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(level & 1)
                reverse(tmp.begin(), tmp.end());
            arr.insert(arr.end(), tmp.begin(), tmp.end());
            level++;
        }
        TreeNode *ans = createTree(arr);
        return ans;
    }

private:
    TreeNode *createTree(vector<int> &arr) {
        TreeNode *root = nullptr;
        queue<TreeNode *> q;
        for(int i = 0; i < arr.size(); i++)
            root = insertValue(root, arr[i], q);
        return root;
    }

    TreeNode *insertValue(TreeNode *root, int value, queue<TreeNode *> &q) {
        TreeNode *node = new TreeNode(value);
        if(!root)
            root = node;
        else if(!(q.front()->left))
            q.front()->left = node;
        else {
            q.front()->right = node;
            q.pop();
        }

        q.push(node);
        return root;
    }
};
