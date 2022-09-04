// https://leetcode.com/problems/longest-nice-subarray/discuss/2527496/JavaC%2B%2BPython-Sliding-Window
// sliding window

class Solution {
public:
    int longestNiceSubarray(vector<int>& A) {
        int AND = 0, i = 0, ans = 0, n = A.size();
        for(int j = 0; j < n; j++) {
            while((AND & A[j]) > 0)
                AND ^= A[i++];
            AND |= A[j];
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
