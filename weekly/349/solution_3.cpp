// https://leetcode.com/problems/collecting-chocolates/solutions/3623841/java-c-python-rotate/
// rotate

class Solution {
public:
    long long minCost(vector<int>& A, int x) {
        int n = A.size();
        vector<long long> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] += 1L * i * x;
            int cur = A[i];
            for(int k = 0; k < n; k++) {
                cur = min(cur, A[(i - k + n) % n]);
                ans[k] += cur;
            }
        }
        return *min_element(begin(ans), end(ans));
    }
};
