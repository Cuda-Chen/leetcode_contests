// https://www.geeksforgeeks.org/final-matrix-after-incrementing-submatrices-by-k-in-range-given-by-q-queries/
// prefix sum

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n)), aux(n, vector<int>(n));
        for(auto &q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            update(x1, x2, y1, y2, 1, aux);
        }
        // update matrix
        for(int i = 0; i < n; i++)
            for(int j = 1; j < n; j++)
                aux[i][j] += aux[i][j - 1];
        for(int i = 0; i < n; i++)
            for(int j = 1; j < n; j++)
                aux[j][i] += aux[j - 1][i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans[i][j] += aux[i][j];
        return ans;
    }
    
private:    
    void update(int x1, int x2, int y1, int y2, int k, vector<vector<int>> &aux) {
        int n = aux.size();
        aux[x1][y1] += k;
        if(x2 + 1 < n)
            aux[x2 + 1][y1] -= k;
        if(x2 + 1 < n && y2 + 1 < n)
            aux[x2 + 1][y2 + 1] += k;
        if(y2 + 1 < n)
            aux[x1][y2 + 1] -= k;
    }
};
