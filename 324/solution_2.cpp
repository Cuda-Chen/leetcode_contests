// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/solutions/2923497/prime-factorization/
// prime factorization

class Solution {
public:
    int smallestValue(int n) {
        int sum = 0, ans = n;
        for(int i = 0; i < 65 && ans >= p[i]; i++) {
            while(ans % p[i] == 0) {
                sum += p[i];
                ans /= p[i];
            }
        }
        return (sum == 0 || sum == n) ? n : smallestValue(sum + (ans == 1 ? 0 : ans));
    }

private:
    int p[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
};
