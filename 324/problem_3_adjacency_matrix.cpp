// MLE
// adjancency matrix
// https://cs.stackexchange.com/questions/135300/graph-add-at-most-2-edges-to-make-all-graph-nodes-degree-even

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n));
        int odd = 0;
        vector<int> odd_v;
        for(auto e : edges) {
            g[e[0] - 1][e[1] - 1] = 1;
            g[e[1] - 1][e[0] - 1] = 1;
        }
        for(int i = 0; i < n; i++) {
            int deg = 0;
            for(int j = 0; j < n; j++) {
                if(g[i][j])
                    deg++;
            }
            if(deg % 2 == 1) {
                odd++;
                odd_v.push_back(i);
            }
        }

        if(odd == 0) {
            return true;
        } else if(odd == 2) {
            int a = odd_v[0], b = odd_v[1];
            for(int k = 0; k < n; k++) {
                if(!g[a][k] && !g[b][k])
                    return true;
            }
            return false;
        } else if(odd == 4) {
            int a = odd_v[0], b = odd_v[1], c = odd_v[2], d = odd_v[3];
            if((!g[a][b] && !g[c][d]) ||
               (!g[a][c] && !g[b][d]) ||
               (!g[a][d] && !g[b][c]))
                return true;
            return false;
        }
        return false;
    }
};
