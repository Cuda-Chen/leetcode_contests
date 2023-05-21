// https://leetcode.com/problems/modify-graph-edge-weights/solutions/3547681/dijkstra-c-commented-code/
// Dijkstra

class Solution {
public:
    vector<vector<int> > modifiedGraphEdges(int n, vector<vector<int> >& edges, int src, int dst, int target)
    {
        vector<vector<pair<int, int> > > g(n);
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w != -1) {
                g[u].push_back({ v, w });
                g[v].push_back({ u, w });
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
        q.push({ 0, src });
        vector<int> dis(n, 1e9);
        dis[src] = 0;
        while (!q.empty()) {
            auto[cur, u] = q.top();
            q.pop();
            if (u == dst) {
                break;
            }

            for (auto n : g[u]) {
                auto[v, wt] = n;
                if (cur + wt < dis[v]) {
                    dis[v] = cur + wt;
                    q.push({ dis[v], v });
                }
            }
        }

        if (dis[dst] < target) {
            return {};
        }
        if (dis[dst] == target) {
            for (auto& e : edges) {
                if (e[2] == -1) {
                    e[2] = 1e9;
                }
            }
            return edges;
        }

        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            if (e[2] == -1) {
                e[2] = 1;
                g[e[1]].push_back({ e[0], 1 });
                g[e[0]].push_back({ e[1], 1 });
                while (!q.empty()) {
                    q.pop();
                }

                q.push({ 0, src });
                vector<int> dis(n, 1e9);
                dis[src] = 0;
                while (!q.empty()) {
                    auto[cur, u] = q.top();
                    q.pop();
                    if (u == dst) {
                        break;
                    }
                    for (auto n : g[u]) {
                        auto[v, wt] = n;
                        if (cur + wt < dis[v]) {
                            dis[v] = cur + wt;
                            q.push({ dis[v], v });
                        }
                    }
                }

                if (dis[dst] <= target) {
                    e[2] += target - dis[dst];
                    for (int j = i + 1; j < edges.size(); j++) {
                        if (edges[j][2] == -1) {
                            edges[j][2] = 1e9;
                        }
                    }
                    return edges;
                }
            }
        }
        return {};
    }
};
