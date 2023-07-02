// https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/solutions/3706561/java-c-python-two-loops-o-n/
// solution 1

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& A) {
        int ans = 0, n = A.size();
        for(int i = 0; i < n; i++) {
            unordered_set<int> s = {A[i]};
            int cur = 0;
            for(int j = i + 1; j < n; j++) {
                cur += s.count(A[j]) ? 0 : 1 - s.count(A[j] + 1) - s.count(A[j] - 1);
                s.insert(A[j]);
                ans += cur;
            }
        }
        return ans;
    }
};
