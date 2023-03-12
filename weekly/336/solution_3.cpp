// https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/solutions/3286372/java-c-python-prefix-xor/
// prefix XOR
// why use XOR: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/solutions/3286256/count-subarrays-with-zero-xor/
// Bits in a beautiful subarray shoudl appear even number of times.

class Solution {
public:
    long long beautifulSubarrays(vector<int>& A) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        long long ans = 0, pre = 0;
        for(int a : A)
            ans += dp[pre ^= a]++;
        return ans;
    }
};
