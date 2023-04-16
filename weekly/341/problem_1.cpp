class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, std::accumulate(begin(mat[i]), end(mat[i]), 0));
        }
        for(int i = 0; i < n; i++) {
            int tmp = std::accumulate(begin(mat[i]), end(mat[i]), 0);
            if(tmp == mx) {
                return {i, mx};
            }
        }
        return {};
    }
};
