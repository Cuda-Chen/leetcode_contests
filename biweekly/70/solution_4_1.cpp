// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/discuss/1709725/JavaC%2B%2BPython-Two-Solutions-with-Explanation
// combination

class Solution {
public:
    int numberOfWays(string s) {
        long ans = 1, j = 0, k = 0, mod = 1e9 + 7;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'S') {
                if(++k > 2 && k % 2 == 1)
                    ans = ans * (i - j) % mod;
                j = i;
            }
        }
        return k % 2 == 0 && k > 0 ? ans : 0;
    }
};
