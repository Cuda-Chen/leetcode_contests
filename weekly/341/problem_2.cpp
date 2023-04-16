class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = divisors.size();
        vector<int> tmp(n);
        for(int i = 0; i < n; i++) {
            int d = divisors[i];
            int cnt = 0;
            for(int num : nums) {
                if((num % d) == 0) {
                    cnt++;
                }
            }
            tmp[i] = cnt;
        }
        int mx = *max_element(begin(tmp), end(tmp)), ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(mx == tmp[i])
                ans = min(ans, divisors[i]);
        }
        return ans;
    }
};
