class Solution {
public:
    int longestAlternatingSubarray(vector<int>& A, int threshold) {
        int n = A.size();
        if(n == 1)
            return A[0] % 2 == 0 && A[0] <= threshold;
        
        int ans = 0, mod, len = 0;
        for(int i = 0; i < n; i++) {
            if((len == 0) && (A[i] % 2 != 0 || A[i] > threshold))
                continue;
            
            if(len == 0 && A[i] % 2 == 0) {
                len++;
            } else {
                if(A[i] > threshold ||
                   (mod == 1 && A[i] % 2 != 0)) {
                    len = 0;
                } else if(mod == 0 && A[i] % 2 != 1) {
                    len = 1;
                } else {
                    len++;
                }
            }
            ans = max(ans, len);
            mod = A[i] % 2;
        }
        return ans;
    }
};
