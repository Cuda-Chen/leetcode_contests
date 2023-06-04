class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int n = A.size();
        if(A[0] == 1 && A.back() == n)
            return 0;
        int ans = 0;
        int a_idx = -1, b_idx = -1;
        for(int i = 0; i < n; i++) {
            if(A[i] == 1) {
                a_idx = i;
                ans += i;
                break;
            }
        }
        //printf("a: %d ", ans);
        for(int i = n - 1; i >= 0; i--) {
            if(A[i] == n) {
                b_idx = i;
                ans += n - i - 1;
                break;
            }
        }
        //printf("b: %d\n", ans);
        //printf("%d %d\n", a_idx, b_idx);
        if(a_idx > b_idx)
            ans -= 1;
        return ans;
    }
};
