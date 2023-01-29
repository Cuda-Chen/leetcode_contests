// https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1534-count-good-triplets/
// btute-force
// TLE

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int l = k + 1; l < n; l++) {
                        if(nums[i] < nums[k] &&
                           nums[k] < nums[j] &&
                           nums[j] < nums[l])
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
