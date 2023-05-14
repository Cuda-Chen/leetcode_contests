// prefix and suffix with hash map

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> p, s;
        for(int num : nums)
            s[num]++;
        for(int num : nums) {
            s[num]--;
            p[num]++;
            1int cnt1 = 0, cnt2 = 0;
            for(auto kv : p) {
                if(kv.second != 0)
                    cnt1++;
            }
            for(auto kv : s) {
                if(kv.second != 0)
                    cnt2++;
            }
            ans.push_back(cnt1 - cnt2);
        }
        return ans;
    }
};
