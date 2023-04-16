// https://leetcode.com/problems/sum-of-distances/solutions/3395732/ltr-rtl/
// prefix sum

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans(nums.size());
        unordered_map<int, long long> m_l, m_r;
        unordered_map<int, long long> cnt_l, cnt_r;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = cnt_l[nums[i]] * i - m_l[nums[i]];
            m_l[nums[i]] += i;
            ++cnt_l[nums[i]];
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] += m_r[nums[i]] - cnt_r[nums[i]] * i;
            m_r[nums[i]] += i;
            ++cnt_r[nums[i]];
        }
        return ans;
    }
};
