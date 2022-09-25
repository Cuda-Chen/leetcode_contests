// https://leetcode.com/problems/find-all-good-indices/discuss/2620563/set_intersection
// set_intersection

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int l_cnt = 1, r_cnt = 1, n = nums.size();
        vector<int> lid, rid;
        for(int i = 1; i < n; i++) {
            if(l_cnt >= k)
                lid.push_back(i);
            if(r_cnt >= k)
                rid.push_back(n - i - 1);
            l_cnt = nums[i] > nums[i - 1] ? 1 : l_cnt + 1;
            r_cnt = nums[n - i - 1] > nums[n - i] ? 1 : r_cnt + 1;
        }
        auto it = set_intersection(begin(lid), end(lid), rbegin(rid), rend(rid), begin(lid));
        return vector<int>(begin(lid), it);
    }
};
