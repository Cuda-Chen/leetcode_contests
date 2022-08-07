class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int pivot = nums[i];
            int cnt = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] - pivot == diff) {
                    pivot = nums[j];
                    cnt++;
                }
                if(cnt == 3)
                    break;
            }
            if(cnt == 3)
                ans++;
        }
        return ans;
    }
};
