// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/discuss/2527381/JavaC%2B%2BPython-Math-Solution-O(klogk)
// math

class Solution {
public:
    int numberOfWays(int a, int b, int k) {
        if((a - b - k) % 2)
            return 0;
        if(abs(a - b) > k)
            return 0;
        long long ans = 1L;
        for(int i = 0; i < (b - a + k) / 2; i++) {
            ans = ans * (k - i) % p;
            ans = ans * inv(i + 1) % p;
        }
        return ans;
    }
    
private:
    int p = 1e9 + 7;
    
    long inv(long a) {
        if(a == 1)
            return 1;
        return (p - p / a) * inv(p % a) % p;
    }
};
