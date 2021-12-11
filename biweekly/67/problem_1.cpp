// sorting
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> temp(n); // index, value
        for(int i = 0; i < n; i++)
            temp[i] = {i, nums[i]};
        sort(temp.begin(), temp.end(), [](const auto &a, const auto &b) {
            return a.second < b.second;
        });
        
        vector<pair<int, int>> temp1; // index, value
        for(int i = 0; i < k; i++)
            temp1.push_back(temp[n - 1 - i]);
        sort(temp1.begin(), temp1.end(), [](const auto &a, const auto &b) {
            return a.first < b.first;
        });
        
        vector<int> ans;
        for(auto a : temp1)
            ans.push_back(a.second);
        
        return ans;
    }
};
