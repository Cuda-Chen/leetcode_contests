// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/discuss/1709725/JavaC%2B%2BPython-Two-Solutions-with-Explanation
// DP

class Solution {
public:
    int numberOfWays(string s) {
        int a = 1, b = 0, b2 = 0, c = 0, mod = 1e9 + 7;
        for(char ch : s) {
            if(ch == 'S')
                a = (a + c) % mod, c = b, b = a, a = 0;
            else
                a = (a + c) % mod;
        }
        return c;
    }
};
