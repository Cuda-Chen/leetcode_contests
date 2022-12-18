// https://leetcode.com/problems/cycle-length-queries-in-a-tree/solutions/2923489/java-c-python-lowest-common-ancestor/
// Lowest Common Ancestor

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m, 1);
        for(int i = 0; i < m; i++) {
            int x = queries[i][0], y = queries[i][1];
            while(x != y) {
                if(x > y)
                    x /= 2;
                else
                    y /= 2;
                ans[i]++;
            }
        }
        return ans;
    }
};
