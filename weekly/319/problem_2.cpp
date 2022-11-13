// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/solutions/2734442/brute-force-vs-count-gcds/
// LCM version of 447. Number of Subarrays With GCD Equal to K

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> lcms;
        for(int i = 0; i < nums.size(); i++) {
            unordered_map<int, int> lcms1;
            if(k % nums[i] == 0) {
                ++lcms[nums[i]];
                for(auto [prev_lcm, cnt] : lcms)
                    lcms1[lcm(prev_lcm, nums[i])] += cnt;
            }
            ans += lcms1[k];
            swap(lcms, lcms1);
        }
        return ans;
    }
};
