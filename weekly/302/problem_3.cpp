// WA
// I have no idea how to get nth-smallest element and its index.

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        vector<int> tmp(nums.size());
        for(int i = 0; i < queries.size(); i++) {
            for(int j = 0; j < nums.size(); j++) {
                tmp[j] = 0;
                int v = stoi(nums[j]);
                int cnt = 1;
                for(int k = 0; k < queries[i][1]; k++) {
                    tmp[j] += (v % 10) * cnt;
                    v /= 10;
                    cnt *= 10;
                }
            }

            int target = INT_MIN, idx = -1;
            for(int j = 0; j < tmp.size(); j++) {
                if(target == tmp[j])
                    continue;
                target = min(target, tmp[j]);
                idx = j;
            }
            ans[i] = idx;
        }
        return ans;
    }
};
