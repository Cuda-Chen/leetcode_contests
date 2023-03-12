// https://leetcode.com/problems/minimum-time-to-complete-all-tasks/solutions/3286244/number-line/

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int line[2001] = {};
        sort(begin(tasks), end(tasks), [](const auto &a, const auto &b) {
            return a[1] < b[1];
        });
        for(auto &t : tasks) {
            int start = t[0], end = t[1], d = t[2];
            d -= count(begin(line) + start, begin(line) + end + 1, true);
            for(int i = end; d > 0; i--) {
                d -= !line[i];
                line[i] = true;
            }
        }
        return count(begin(line), end(line), true);
    }
};
