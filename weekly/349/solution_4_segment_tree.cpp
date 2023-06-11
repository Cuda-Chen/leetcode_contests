// https://leetcode.com/problems/maximum-sum-queries/solutions/3623791/segment-tree-c-and-python/
// segment tree

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& A, vector<int>& B, vector<vector<int>>& qs) {
        int n = A.size();
        map<int, int> all;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            ++all[B[i]];
            v[i] = {A[i], B[i]};
        }
        sort(v.begin(), v.end());
        int m = qs.size();
        vector<int> ind(m);
        for(int i = 0; i < m; i++) {
            ind[i] = i;
            ++all[qs[i][1]];
        }
        sort(ind.begin(), ind.end(), [&](const auto &a, const auto &b) {
            return qs[a][0] > qs[b][0];
        });
        int mv = 0;
        for(auto &p : all)
            p.second = ++mv;
        vector<int> tree(mv << 2, -1);
        vector<int> r(m);
        for(int i = 0, j = n - 1; i < m; i++) {
            for(; j >= 0 && v[j].first >= qs[ind[i]][0]; update(tree, 1, 1, mv, all[v[j].second], v[j].first + v[j].second), --j)
                ;
            r[ind[i]] = query(tree, 1, 1, mv, all[qs[ind[i]][1]], mv);
        }
        return r;
    }

private:
    int query(vector<int> &tree, int ind, int l, int r, int x, int y) {
        if(l >= x && r <= y)
            return tree[ind];
        int m = l + (r - l) / 2;
        int rr = -1;
        if(x <= m)
            rr = query(tree, ind << 1, l, m, x, y);
        if(y > m)
            rr = max(rr, query(tree, (ind << 1) | 1, m + 1, r, x, y));
        return rr;
    }

    void update(vector<int> &tree, int ind, int l, int r, int x, int y) {
        tree[ind] = max(tree[ind], y);
        if(l >= x && r <= x)
            return;
        int m = l + (r - l) / 2;
        if(x <= m)
            update(tree, ind << 1, l, m, x, y);
        else
            update(tree, (ind << 1) | 1, m + 1, r, x, y);
    }
};
