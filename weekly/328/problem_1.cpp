// simulation

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elem_sum = accumulate(begin(nums), end(nums), 0);
        int digit_sum = 0;
        for(int num : nums) {
            while(num) {
                digit_sum += num % 10;
                num /= 10;
            }
        }
        return abs(elem_sum - digit_sum);
    }
};
