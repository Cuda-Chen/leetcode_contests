// https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/solutions/3706561/java-c-python-two-loops-o-n/
// solution 2

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& A) {
        int ans = 0, n = A.size();
        vector<int> left(n), seen(n + 10, -1);
        for(int i = 0; i < n; i++) {
            left[i] = max(seen[A[i] + 1], seen[A[i]]);
            seen[A[i]] = i;
        }
        seen.assign(n + 10, n);
        for(int i = n - 1; i >= 0; i--) {
            seen[A[i]] = i;
            ans += (i - left[i]) * (seen[A[i] + 1] - i);
        }
        return ans - n * (n + 1) / 2;
    }
};
