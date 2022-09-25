// Find max element, then record the length

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        int max_val = nums[idx];
        int ans = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == max_val)
                cur++;
            else {
                ans = max(ans, cur);
                cur = 0;
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};
