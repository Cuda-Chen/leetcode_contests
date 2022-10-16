// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/discuss/2708099/JavaC%2B%2BPython-Sliding-Window-with-Explanation
// sliding window

class Solution {
public:
    long long countSubarrays(vector<int>& A, int minK, int maxK) {
        long ans = 0, j = 0, jmin = -1, jmax = -1, n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] < minK || A[i] > maxK) {
                jmin = jmax = -1;
                j = i + 1;
            }
            if(A[i] == minK)
                jmin = i;
            if(A[i] == maxK)
                jmax = i;
            ans += max(0L, min(jmin, jmax) - j + 1);
        }
        return ans;
    }
};
