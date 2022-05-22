// https://leetcode.com/problems/sum-of-total-strength-of-wizards/discuss/2061787/Amazon-Online-Assessment
// 84. Largest Rectangle in Histogram + prefix sum

class Solution {
public:
    int totalStrength(vector<int>& s) {
        long long ans = 0, n = s.size(), kMod = 1e9 + 7;
        vector<int> ps_l(n + 1), pm_l(n + 1); // prefix sum and mul from the left
        vector<int> ps_r(n + 1), pm_r(n + 2); // prefix sum and mul from the right
        vector<int> st; // mono-stack
        for(long long i = 0; i < n; i++) {
            ps_l[i + 1] = (ps_l[i] + s[i]) % kMod;
            pm_l[i + 1] = (pm_l[i] + (i + 1) * s[i]) % kMod;
        }
        for(long long i = n - 1; i >= 0; i--) {
            ps_r[i] = (ps_r[i + 1] + s[i]) % kMod;
            pm_r[i] = (pm_r[i + 1] + (n - i) * s[i]) % kMod;
        }
        
        for(int r = 0; r <= n; r++) {
            while(!st.empty() && (r == n || s[st.back()] >= s[r])) {
                int pivot = st.back();
                st.pop_back();
                long long l = st.empty() ? 0 : st.back() + 1;
                long long left_sum = (kMod + pm_l[pivot + 1] - pm_l[l] - l * (ps_l[pivot + 1] - ps_l[l]) % kMod) % kMod;
                long long right_sum = (kMod + pm_r[pivot + 1] - pm_r[r] - (n - r) * (ps_r[pivot + 1] - ps_r[r])) % kMod;
                long long all_sum = (right_sum * (pivot - l + 1) + left_sum * (r - pivot)) % kMod;
                ans = (ans + all_sum * s[pivot]) % kMod;
            }
            st.push_back(r);
        }
        return ans;
    }
};
