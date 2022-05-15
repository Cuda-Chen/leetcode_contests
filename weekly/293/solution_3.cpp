// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/discuss/2039903/JavaC%2B%2BPython-Bit-Solution
// bit operation

class Solution {
public:
    int largestCombination(vector<int>& A) {
        int ans = 0, cur = 0;
        for(int i = 1; i <= 10000000; i <<= 1) {
            cur = 0;
            for(int &a : A)
                if(a & i)
                    cur++;
            ans = max(ans, cur);
        }
        return ans;
    }
};
