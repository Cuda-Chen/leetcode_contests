// brute-force
// TLE

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n));
        
        for(auto q : queries) {
            int type = q[0], idx = q[1], val = q[2];
            if(type == 0) {
                for(int j = 0; j < n; j++)
                    mat[idx][j] = val;
            } else if(type == 1) {
                for(int i = 0; i < n; i++)
                    mat[i][idx] = val;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
                ans += mat[i][j];
        }
        return ans;
    }
};
