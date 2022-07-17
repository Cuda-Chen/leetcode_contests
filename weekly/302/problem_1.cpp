// counting sort

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> cnt(101);
        for(int num : nums)
            cnt[num]++;
        int ans = 0, left = 0;
        for(int i = 0; i < cnt.size(); i++) {
            ans += cnt[i] / 2;
            cnt[i] %= 2;
        }
        left = accumulate(begin(cnt), end(cnt), 0);
        return {ans, left};
    }
};
