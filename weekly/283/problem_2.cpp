// hash set
// TLE
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        unordered_set<int> s(begin(nums), end(nums));
        long long temp = 0, ans = 0;
        
        while(k) {
            temp++;
            if(!s.count(temp)) {
                ans += temp;
                k--;
            }
        }
        return ans;
    }
};
