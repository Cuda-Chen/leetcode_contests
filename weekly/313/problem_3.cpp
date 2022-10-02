// binary manipulation
// Set all bits of num1, then put remain number of cnt in lower bit position.

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        int n = 32;
        vector<int> b(n, 0), ans_b(n, 0);
        for(int i = 31; i >= 0; i--) {
            if((num1 >> (n - 1 - i)) & 1)
                b[i] = 1;
        }
        for(int i = 0; i < n; i++) {
            if(b[i]) {
                ans_b[i] = b[i];
                cnt--;
            }
            if(cnt == 0)
                break;
        }
        int idx = n - 1;
        while(cnt) {
            if(ans_b[idx]) {
                idx--;
                continue;
            }
            
            ans_b[idx] = 1;
            idx--;
            cnt--;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(ans_b[i])
                ans |= 1 << (n - 1 - i);
        }
        return ans;
    }
};
