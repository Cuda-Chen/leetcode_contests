// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/3395750/java-c-python-binary-search/
// binary search

class Solution {
public:
    int minimizeMax(vector<int>& A, int p) {
        sort(A.begin(), A.end());
        int n = A.size(), l = 0, r = A[n - 1] - A[0];
        while(l < r) {
            int m = l + (r - l) / 2, k = 0;
            for(int i = 1; i < n && k < p; i++) {
                if(A[i] - A[i - 1] <= m) {
                    k++;
                    i++;
                }
            }
            if(k >= p)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
