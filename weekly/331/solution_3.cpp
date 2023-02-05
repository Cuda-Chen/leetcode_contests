// https://leetcode.com/problems/house-robber-iv/solutions/3143697/java-c-python-binary-search-o-1-space/
// binary search

class Solution {
public:
    int minCapability(vector<int>& A, int k) {
        int l = 1, r = 1e9, n = A.size();
        while(l < r) {
            int m = l + (r - l) / 2, take = 0;
            for(int i = 0; i < n; i++) {
                if(A[i] <= m) {
                    take += 1;
                    i++;
                }
            }
            if(take >= k)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
