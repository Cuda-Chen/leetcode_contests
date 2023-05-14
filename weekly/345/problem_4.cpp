// DFS
// WA

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto e : edges) {
            g[e[1]].push_back(e[0]);
            g[e[0]].push_back(e[1]);
        }
        vector<int> seen(n);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> tmp;
            if(seen[i] == 0) {
                dfs(g, seen, tmp, i);    
            }
            for(int num : tmp) {
                bool flag = true;
                if(g[num].size() != tmp.size() - 1) {
                    flag = false;
                    break;
                }
                if(flag)
                    ans++;
            }
        }
        
        return ans;
    }
    
private:
    void dfs(vector<vector<int>> &g, vector<int> &seen, vector<int> &tmp, int src) {
        seen[src] = 1;
        tmp.push_back(src);
        for(int v : g[src]) {
           if(!seen[v])
               dfs(g, seen, tmp, v);
        }
    }
};

// AC
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto e : edges) {
            g[e[1]].push_back(e[0]);
            g[e[0]].push_back(e[1]);
        }
        vector<int> seen(n);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> tmp;
            if(seen[i] == 0) {
                dfs(g, seen, tmp, i);    
            }
            if(!tmp.empty()) {
            bool flag = true;
            for(int num : tmp) {
                if(g[num].size() != tmp.size() - 1) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
            }
        }
        
        return ans;
    }
    
private:
    void dfs(vector<vector<int>> &g, vector<int> &seen, vector<int> &tmp, int src) {
        seen[src] = 1;
        tmp.push_back(src);
        for(int v : g[src]) {
           if(!seen[v])
               dfs(g, seen, tmp, v);
        }
    }
};
