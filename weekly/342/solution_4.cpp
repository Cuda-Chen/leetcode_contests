// https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/solutions/3445895/smallest-subarray-gcd-equal-to-1-very-simple-easy-to-understand-solution/?q=C%2B%2B&orderBy=most_votes
// greedy

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int t = INT_MAX, cnt = 0;
        for(auto n : nums) {
            if(n == 1)
                cnt++;
        }
        if(cnt > 0)
            return nums.size() - cnt;
        for(int i = 0; i < nums.size(); i++) {
            int last = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                last = __gcd(last, nums[j]);
                if(last == 1) {
                    t = min(t, j - i);
                    break;
                }
            }
        }
        return t != INT_MAX ? t + nums.size() - 1 : -1;
    }
};
