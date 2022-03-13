// brute-force

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<pair<int, int>>> mat(n, vector<pair<int, int>>(n, make_pair(-1, 0)));
        for(int l = 0; l < artifacts.size(); l++) {
            auto a = artifacts[l];
            for(int i = a[0]; i <= a[2]; i++)
                for(int j = a[1]; j <= a[3]; j++)
                    mat[i][j] = {l, 1};
        }
        for(auto d : dig) {
            mat[d[0]][d[1]].second = 0;
        }
        int ans = 0;
        for(int l = 0; l < artifacts.size(); l++) {
            auto a = artifacts[l];
            bool flag = true;
            for(int i = a[0]; i <= a[2]; i++)
                for(int j = a[1]; j <= a[3]; j++)
                    if(mat[i][j].second == 1) flag = false;
            if(flag) ans++;
        }
        return ans;
    }
};
