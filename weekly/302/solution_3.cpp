// https://leetcode.com/problems/query-kth-smallest-trimmed-number/discuss/2292757/C%2B%2B-or-Priority-Queue-or-Easy-Code
// priority queue

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x : queries) {
            priority_queue<pair<string, int>> v;
            for(int i = 0; i < nums.size(); i++) {
                int t = nums[i].size() - x[1];
                string p = nums[i].substr(t, x[1]);
                if(v.size() < x[0])
                    v.push({p, i});
                else {
                    if(v.top().first > p) {
                        v.pop();
                        v.push({p, i});
                    }
                }
            }
            int val = v.top().second;
            ans.push_back(val);
        }
        return ans;
    }
};
