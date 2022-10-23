// https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/discuss/2734158/C%2B%2B-Simple-Code-with-Dry-Run-or-Faster-than-100

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            int curGCD = 0;
            for(int j = i; j < nums.size(); j++) {
                curGCD = gcd(curGCD, nums[j]);
                if(curGCD == k)
                    cnt++;
            }
        }
        return cnt;
    }
};
