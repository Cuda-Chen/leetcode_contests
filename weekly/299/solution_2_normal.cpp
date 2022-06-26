// https://leetcode.com/problems/count-number-of-ways-to-place-houses/discuss/2198269/JavaC%2B%2BPython-Fibo-Sequence-O(logn)
// Fibonacci like

class Solution {
public:
    int countHousePlacements(int n) {
        int a = 1, b = 1, c = 2, mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
        return 1L * b * b % mod;
    }
};
