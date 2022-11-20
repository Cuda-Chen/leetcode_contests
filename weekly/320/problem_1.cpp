// TLE

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> ans;
        vector<int> used(n);
        vector<pair<int, int>> path;
        function<void(int)> dfs = [&](int d) {
            if(d == 3) {
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(used[i])
                    continue;
                used[i] = 1;
                path.push_back({nums[i], i});
                dfs(d + 1);
                path.pop_back();
                used[i] = 0;
            }
        };
        dfs(0);
        int cnt = 0;
        for(auto a : ans) {
            //cout << a[0].first << " " << a[0].second << " " << a[1].first << " " << a[1].second << " " << a[2].first << " " << a[2].second << endl;
            unordered_set<int> s({a[0].first, a[1].first, a[2].first});
            if(s.size() == 3 && (a[0].second < a[1].second && a[1].second < a[2].second))
                cnt++;
        }
        //cout << endl;
        return cnt;
    }
};
