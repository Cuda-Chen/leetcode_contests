class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums), [](const auto &a, const auto &b) {
            return b < a;
        });
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        int ans = 0;
        for(auto num : prefix) {
            if(num > 0)
                ans++;
        }
        return ans;
    }
};
