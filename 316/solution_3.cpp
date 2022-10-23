// https://leetcode.com/problems/minimum-cost-to-make-array-equal/discuss/2734162/C%2B%2BPython-Binary-Search
// binary search

class Solution {
public:
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1e6, ans = f(A, cost, 1), x;
        while(l < r) {
            x = l + (r - l) / 2;
            long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
            ans = min(y1, y2);
            if(y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return ans;
    }
    
    long long f(vector<int> &A, vector<int> &cost, int x) {
        long long ans = 0;
        for(int i = 0; i < A.size(); i++)
            ans += 1L * abs(A[i] - x) * cost[i];
        return ans;
    }
};
