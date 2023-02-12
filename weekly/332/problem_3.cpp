class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        for(auto q : queries) {
            int target = q[1] ^ q[0];
            string p = (target == 0) ? "0" : "";
            while(target) {
                int t = target % 2;
                p += to_string(t);
                target /= 2;
            }
            reverse(p.begin(), p.end());
            size_t found = s.find(p);
            if(found == string::npos) {
                ans.push_back({-1, -1});
                continue;
            }
            ans.push_back({static_cast<int>(found), static_cast<int>(found + p.size() - 1)});
        }
        return ans;
    }
};
