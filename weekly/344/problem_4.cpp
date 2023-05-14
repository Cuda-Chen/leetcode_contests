// WA
// you should just consider each left/right children of each node

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int total = (n + 1) / 2;
        int ans = 0;
        while(total != 1) {
            int mx = INT_MIN;
            for(int i = n - 1; i >= total - 1; i--)
                mx = max(mx, cost[i]);
            for(int i = n - 1; i >= total - 1; i--)
                ans += (mx - cost[i]);
            n -= total;
            total /= 2;
        }
        cout << endl;
        return ans;
    }
};
