// OJ: https://leetcode.com/contest/weekly-contest-282/problems/minimum-time-to-complete-trips/
// Author: github.com/lzl124631x
// Time: O(NlogM) where M is the maximum possible answer
// Space: O(1)

class Solution {
public:
    long long minimumTime(vector<int>& A, int totalTrips) {
        long long l = 1, r = LONG_MAX;
        auto valid = [&](long long time) { // returns true if we can finish `totalTrips` trips given `time`
            long long sum = 0;
            for(long long n : A) {
                sum += time / n;
                if(sum >= totalTrips) return true;
            }
            return false;
        };
        while(l <= r) {
            long long mid = l + (r - l) / 2;
            if(valid(mid)) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};
