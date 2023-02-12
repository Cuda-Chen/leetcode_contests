// https://leetcode.com/problems/substring-xor-queries/solutions/3174035/hash-map/
// hash map

class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> m;
        vector<vector<int>> ans;
        for(int i = 0; i < s.size(); i++) {
            long long val = 0;
            for(int j = 0; j < 32 && i + j < s.size(); j++) {
                val = (val << 1) + (s[i + j] == '1');
                if(m.count(val) == 0)
                    m[val] = {i, i + j};
                if(s[i] == '0')
                    break;
            }
        }
        for(const auto &q : queries) {
            if(auto it = m.find(q[0] ^ q[1]); it != end(m))
                ans.push_back(it->second);
            else
                ans.push_back({-1, -1});
        }
        return ans;
    }
};
