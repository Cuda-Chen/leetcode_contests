// WA
class Solution {
public:
    int numberOfWays(string corridor) {        
        int n = corridor.size(), seatCnt = 0;
        const int kMod = 1e9 + 7;
        vector<int> arr(n, 0); // accumulate count of seats
        arr[0] = (corridor[0] == 'S') ? 1 : 0;
        seatCnt = (corridor[0] == 'S') ? 1 : 0;
        for(int i = 1; i < n; i++) {
            if(corridor[i] == 'S') {
                arr[i] = arr[i - 1] + 1;
                seatCnt++;
            } else {
                arr[i] = arr[i - 1];
            }
        }
        cout << seatCnt << endl;
        
        if((seatCnt % 2 != 0) || (seatCnt == 0)) return 0;
        if(seatCnt == 2) return 1;
        int ans = 1;
        for(int target = 2; target < seatCnt; target += 2) {
            auto low = lower_bound(begin(arr), end(arr), target);
            auto up = upper_bound(begin(arr), end(arr), target);
            cout << ((up - arr.begin()) - (low - arr.begin())) << endl;
            ans *= ((up - arr.begin()) - (low - arr.begin()));
            ans %= kMod;
        }
        
        return ans;
    }
};
