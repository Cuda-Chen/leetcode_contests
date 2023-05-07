// https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/solutions/3494915/java-c-python-bottom-up-and-follow-up/

class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        int ans = 0;
        for(int i = n / 2 - 1; i >= 0; i--) {
            int l = i * 2 + 1, r = i * 2 + 2;
            ans += abs(A[l] - A[r]);
            A[i] += max(A[l], A[r]);
        }
        return ans;
    }
};
