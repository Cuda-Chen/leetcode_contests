// TLE

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++)
            m[nums[i]].push_back(i);
        for(auto kv : m) {
            int sz = kv.second.size();
            if(sz == 1) {
                ans[kv.second[0]] = 0;
                continue;
            }
            
            for(int i = 0; i < sz; i++) {
                long long tmp = 0;
                for(int j = i - 1; j >= 0; j--)
                    tmp += abs(kv.second[i] - kv.second[j]);
                for(int j = i + 1; j < sz; j++)
                    tmp += abs(kv.second[i] - kv.second[j]);
                ans[kv.second[i]] = tmp;
            }
        }
        return ans;
    }
};
