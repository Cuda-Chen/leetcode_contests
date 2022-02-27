// WA

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        if(time.size() == 1) return (long long)time[0] * totalTrips;
        
        auto sums = [&](int d) {
            int s = 0;
            for(int t : time)
                s += d / t;
            return s;
        };
        
        long long l = 1, r = 1e7;
        while(l < r) {
            long long mid = l + (r - l) / 2;
            if(sums(mid) >= totalTrips)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
