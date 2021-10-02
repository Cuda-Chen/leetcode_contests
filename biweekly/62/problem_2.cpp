// permutation
// Also test reversed tuple pair
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string temp = nums[i] + nums[j];
                if(temp == target) cnt++;
                string temp1 = nums[j] + nums[i];
                if(temp1 == target) cnt++;
            }
        }
        return cnt;
    }
};
