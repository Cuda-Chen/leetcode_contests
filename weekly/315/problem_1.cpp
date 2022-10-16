// count with arrays

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> cnt_p(1001), cnt_n(1001); // positive and negative numbers
        for(int num : nums) {
            num < 0 ? cnt_n[abs(num)]++ : cnt_p[num]++;
        }
        int ans = -1;
        for(int i = 1; i <= 1000; i++) {
            if(cnt_n[i] && cnt_p[i])
                ans = i;
        }
        return ans;
    }
};
