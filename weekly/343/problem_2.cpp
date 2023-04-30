// hash map

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> mp; // {num, {i, j}}
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[mat[i][j]] = make_pair(i, j);
            }
        }
        unordered_map<int, int> r, c; // {idx, count}
        int ans = -1;
        for(int i = 0; i < m * n; i++) {
            ans++;
            auto [y, x] = mp[arr[i]];
            r[y]++;
            c[x]++;
            if(r[y] == n || c[x] == m)
                break;
        }
        return ans;
    }
};
