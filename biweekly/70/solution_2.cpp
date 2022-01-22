// https://leetcode.com/problems/count-the-hidden-sequences/discuss/1709755/JavaC%2B%2BPython-Straight-Forward-Solution-with-Explantion

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long a = 0, ma = 0, mi = 0;
        for(int d : diff) {
            a += d;
            ma = max(ma, a);
            mi = min(mi, a);
        }
        return max(0L, (upper - lower) - (ma - mi) + 1);
    }
};
