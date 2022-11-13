// level-order traversal + Minimum number of swaps required to sort an array
// Minimum number of swaps required to sort an array: https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/

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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode *> q{{root}};
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
            ans += minSwaps(tmp);
        }
        return ans;
    }
    
private:
    int minSwaps(vector<int> arr) {
        int n = arr.size();
        int cnt = 0;
        vector<int> temp = arr;
        unordered_map<int, int> m;
        sort(temp.begin(), temp.end());
        for(int i = 0; i < n; i++)
            m[arr[i]] = i;
        for(int i = 0; i < n; i++) {
            if(arr[i] != temp[i]) {
                cnt++;
                int init = arr[i];
                swap(arr, i, m[temp[i]]);
                m[init] = m[temp[i]];
                m[temp[i]] = i;
            }
        }
        return cnt;
    }
    
    void swap(vector<int> &arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
};
