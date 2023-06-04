// brute-force
// TLE

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int mod = 1e9 + 7;
        int ans = 0;
        for(long i = stol(num1); i <= stol(num2); i++) {
            long sum = 0, num = i;
            while(num) {
                sum += (num % 10);
                num /= 10;
            }
            if((long)min_sum <= sum && sum <= (long)max_sum) {
                //cout << i << " ";
                ans++;
                ans %= mod;
            }
        }
        //cout << endl;
        return ans;
    }
};
