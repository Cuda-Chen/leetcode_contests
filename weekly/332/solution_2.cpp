// https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/3174181/two-pointers-2/
// sort then two pointers

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        return countLess(nums, upper + 1) - countLess(nums, lower);
    }
    
private:
    long long countLess(vector<int> &nums, int val) {
        long long ans = 0;
        for(int i = 0, j = nums.size() - 1; i < j; i++) {
            while(i < j && nums[i] + nums[j] >= val)
                j--;
            ans += j - i;
        }
        return ans;
    }
};
