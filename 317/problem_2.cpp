// sorting
// TLE

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++)
            m[creators[i]] += views[i];

        vector<pair<int, string>> v;
        for(auto kv : m)
            v.push_back({kv.second, kv.first});
        sort(v.rbegin(), v.rend());
        int mx = v[0].first;

        vector<vector<string>> ans;
        for(auto kv : m) {
            if(kv.second < mx)
                continue;

            string creator = kv.first;
            vector<pair<int, string>> t;
            for(int i = 0; i < n; i++) {
                if(creators[i] == creator) {
                    t.push_back({views[i], ids[i]});
                }
            }
            sort(t.begin(), t.end(), [](const auto &a, const auto &b) {
                if(a.first == b.first)
                    return a.second < b.second;
                return a.first > b.first;
            });
            ans.push_back({creator, t[0].second});
        }
        return ans;
    }
};
