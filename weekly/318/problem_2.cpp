// set
// TLE

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            unordered_set<int> s;
            for(int l = i; l <= j; l++)
                s.insert(nums[l]);
            if(s.size() == k) {
                long long tmp = 0;
                for(int e : s)
                    tmp += e;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
