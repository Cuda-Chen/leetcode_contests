class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool ans = true;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    if(!grid[i][j])
                        ans = false;
                } else if(i + j == n - 1) {
                    if(!grid[i][j])
                        ans = false;
                } else {
                    if(grid[i][j])
                        ans = false;
                }
            }
        }
        return ans;
    }
};
