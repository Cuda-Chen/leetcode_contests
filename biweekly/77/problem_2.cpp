// prefix-sum

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long n = nums.size();
        if(n == 1) return 0;
        long sum = accumulate(nums.begin(), nums.end(), 0L);
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        long tmp = LONG_MAX;
        int idx;
        for(int i = 0; i < n; i++) {
            long c = i + 1;
            long a = prefix[i] / c;
            long b = (n - c) == 0 ? 0 : (sum - prefix[i]) / (n - c);
            if(abs(a - b) < tmp) {
                tmp = abs(a - b);
                idx = i;
            }
        }
        return idx;
    }
};
