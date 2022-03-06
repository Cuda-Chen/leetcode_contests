// OJ: https://leetcode.com/contest/weekly-contest-283/problems/replace-non-coprime-numbers-in-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& A) {
        int j = 0, N = A.size();
        for(int i = 0; i < N; i++, j++) {
            A[j] = A[i];
            for(; j - 1 >= 0 && gcd(A[j], A[j - 1]) > 1; j--) { // When we can merge leftwards from `A[j]`, keep merging
                A[j - 1] = (long)A[j] * A[j - 1] / gcd(A[j], A[j - 1]); // replace `A[j - 1]` with LCM of `A[j - 1]` and `A[j]`.
            }
        }
        A.resize(j);
        return A;
    }
};
