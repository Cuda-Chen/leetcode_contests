// https://leetcode.com/problems/maximum-score-of-spliced-array/discuss/2198244/Python-Kadane-Solution
// Kadane's algorithm

class Solution {
public:
    int maximumsSplicedArray(vector<int>& A, vector<int>& B) {
        return max(kadane(A, B),
                   kadane(B, A));
    }

private:
    int kadane(vector<int> &A, vector<int> &B) {
        int ans = 0, cur = 0;
        for(int i = 0; i < A.size(); i++) {
            cur = max(0, cur + A[i] - B[i]);
            ans = max(ans, cur);
        }
        return ans + accumulate(B.begin(), B.end(), 0);
    }
};
