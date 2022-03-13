// brute-force

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<pair<int, int>> idxs;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == key) idxs.push_back({i - k, i + k});
        for(auto idx : idxs) {
            for(int i = idx.first; i <= idx.second; i++) {
                if(i < 0 || i >= nums.size())
                    continue;
                else
                    s.insert(i);
            }
        }
        vector<int> ans;
        for(int i : s)
            ans.push_back(i);
        sort(begin(ans), end(ans));
        return ans;
    }
};
