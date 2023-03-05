// priority queue (for sorting) + level order traversal

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode *> q{{root}};
        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            while(size--) {
                auto t = q.front();
                q.pop();
                sum += t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            pq.push(sum);
        }
        
        long long ans = -1;
        if(pq.size() < k)
            return ans;
        while(k--) {
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};
