// WA

class Solution {
public:
    long long minCost(vector<int>& A, int x) {
        long long ref = accumulate(begin(A), end(A), 0LL);
        int start = INT_MAX, start_idx = -1;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] < start) {
                start = A[i];
                start_idx = i;
            }
        }
        long long sum = 0;
        sum = (start * n) + (x * (n - 1));
        return ref > sum 
            ? sum
            : ref;
    }
};
