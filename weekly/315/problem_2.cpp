// set

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        for(int num : nums) {
            int reverse = 0;
            while(num) {
                reverse = reverse * 10 + num % 10;
                num /= 10;
            }
            s.insert(reverse);
        }
        return s.size();
    }
};
