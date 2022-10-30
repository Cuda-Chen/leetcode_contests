// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/discuss/2757973/Eat-from-right

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0, mul = 1;
        for(; sumDigits(n) > target; mul *= 10) {
            ans += mul * ((10 - n % 10) % 10);
            n = (n + (10 - n % 10) % 10) / 10;
        }
        return ans;
    }
    
    int sumDigits(long long n) {
        int ans = 0;
        for(; n; n /= 10)
            ans += n % 10;
        return ans;
    }
};
