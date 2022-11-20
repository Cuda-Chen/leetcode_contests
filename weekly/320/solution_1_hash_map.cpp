// https://leetcode.com/problems/number-of-unequal-triplets-in-array/solutions/2831702/o-n/
// hash map

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int n : nums)
            m[n]++;
        int ans = 0, l = 0, r = nums.size();
        for(auto [n, cnt] : m) {
            r -= cnt;
            ans += l * cnt * r;
            l += cnt;
        }
        return ans;
    }
};
