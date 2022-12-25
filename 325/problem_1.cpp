// hash table

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        unordered_map<string, vector<int>> m;
        for(int i = 0; i < n; i++)
            m[words[i]].push_back(i);
        int ans = INT_MAX;
        if(!m.count(target))
            return -1;
        for(auto i : m[target]) {
            int t = abs(startIndex - i);
            int comp = n - t;
            ans = min({ans, t, comp});
        }
        return ans;
    }
};
