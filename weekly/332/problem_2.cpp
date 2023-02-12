// TLE

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int tmp = nums[i] + nums[j];
                if(tmp >= lower && tmp <= upper)
                    ans++;
            }
        }
        return ans;
    }
};
