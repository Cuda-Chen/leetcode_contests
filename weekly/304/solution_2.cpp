// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/discuss/2357789/JavaC%2B%2BPython-One-line-O(1)
// sorting

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, total = 0, n = grades.size();
        while(total + k + 1 <= n)
            total += ++k;
        return k;
    }
};
