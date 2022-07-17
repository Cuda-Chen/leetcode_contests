// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/discuss/2292651/JavaC%2B%2BPython-GCD-O(n-%2B-m-%2B-log)
// math (GCD)

class Solution {
public:
    int minOperations(vector<int>& A, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(int a : numsDivide)
            g = gcd(g, a);
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size() && A[i] <= g; i++)
            if(g % A[i] == 0)
                return i;
        return -1;
    }
};
