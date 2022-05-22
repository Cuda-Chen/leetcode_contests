// math
// Beware of machine epsilon

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size() == 1)
            return 0;
        sort(stockPrices.begin(), stockPrices.end());
        int n = stockPrices.size();
        int ans = 1;
        long double m = (long double)(stockPrices[1][1] - stockPrices[0][1]) / (stockPrices[1][0] - stockPrices[0][0]);
        for(int i = 2; i < n; i++) {
            int a = (stockPrices[i][1] - stockPrices[i - 1][1]),
                b = (stockPrices[i][0] - stockPrices[i - 1][0]);
            long double tmp = (long double)a / b;
            if(abs(tmp - m) < LDBL_EPSILON) {
                continue;
            }
            ans++;
            m = tmp;
        }
        return ans;
    }
};
