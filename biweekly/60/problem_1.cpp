// Find the Middle Index in Array

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int leftSum = (i - 1 < 0) ? 0 : accumulate(nums.begin(), nums.begin() + i - 1 + 1, 0);
            int rightSum = (i + 1 >= n) ? 0 : accumulate(nums.begin() + i + 1, nums.end(), 0);
            if(leftSum == rightSum) return i;
        }
        
        return -1;
    }
};
