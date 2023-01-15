// https://leetcode.com/problems/count-the-number-of-good-subarrays/solutions/3052559/c-python-sliding-window/
// hash map + two pointers

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> cnt;
        for(int i = 0, j = 0; j < nums.size(); j++) {
            k -= cnt[nums[j]]++;
            while(k <= 0)
                k += --cnt[nums[i++]];
            ans += i;
        }
        return ans;
    }
};
