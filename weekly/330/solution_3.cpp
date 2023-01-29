// https://leetcode.com/problems/put-marbles-in-bags/solutions/3111736/java-c-python-2-lines-o-nlogk/
// pick k largest/smallest from n numbers.

class Solution {
public:
    long long putMarbles(vector<int>& A, int k) {
        long long ans = 0, n = A.size() - 1;
        for(int i = 0; i < n; i++)
            A[i] += A[i + 1];
        A.pop_back();
        sort(A.begin(), A.end());
        for(int i = 0; i < k - 1; i++)
            ans += A[n - 1 - i] - A[i];
        return ans;
    }
};
