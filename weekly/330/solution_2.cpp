// https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/solutions/3111664/java-c-python-fast-pow/
// math (fast pow)

class Solution {
public:
    int monkeyMove(int n) {
        long ans = 1, base = 2, mod = 1e9 + 7;
        while(n > 0) {
            if(n % 2)
                ans = ans * base % mod;
            base = base * base % mod;
            n >>= 1;
        }
        return (ans - 2 + mod) % mod;
    }
};
