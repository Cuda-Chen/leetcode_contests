// https://leetcode.com/problems/maximum-sum-queries/solutions/3624007/simple-map-solution-in-c/
// C++ map

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& A, vector<int>& B, vector<vector<int>>& qs) {
        int n = A.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++)
            v[i] = {A[i], B[i]};
        sort(v.begin(), v.end());
        int m = qs.size();
        vector<int> ind(m);
        for(int i = 0; i < m; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(), [&](const auto &x, const auto &y) {
            return qs[x][0] > qs[y][0];
        });
        vector<int> r(m);
        map<int, int> vals;
        for(int i = 0, j = n - 1; i < m; i++) {
            for(; j >= 0 && v[j].first >= qs[ind[i]][0]; update(vals, v[j].second, v[j].first + v[j].second), j--)
                ;
            r[ind[i]] = query(vals, qs[ind[i]][1]);
        }
        return r;
    }

private:
    void update(map<int, int> &vals, int key, int value) {
        auto it = vals.lower_bound(key);
        if(it != vals.end() && it->second >= value)
            return;
        if(it != vals.begin()) {
            it--;
            while(it->second <= value) {
                if(it == vals.begin()) {
                    vals.erase(it);
                    break;
                } else {
                    vals.erase(it--);
                }
            }
        }
        vals.insert({key, value});
    }

    int query(map<int, int> &vals, int key) {
        auto it = vals.lower_bound(key);
        return it == vals.end()
            ? -1
            : it->second;
    }
};
