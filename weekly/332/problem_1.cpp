// simulation

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            string a = to_string(nums[l]);
            string b = to_string(nums[r]);
            string tmp = a + b;
            ans += stoi(tmp);
            l++;
            r--;
        }
        if(l == r) {
            string a = to_string(nums[l]);
            ans += stoi(a);
        }
        return ans;
    }
};
