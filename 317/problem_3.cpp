// simulation
// TLE

class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long sum = 0;
        long long tmp = n;
        while(tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if(sum <= target)
            return 0;

        long long ans = 0;
        while(sum > target) {
            n++;
            ans++;
            tmp = n;
            sum = 0;
            while(tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
        }

        return ans;
    }
};
