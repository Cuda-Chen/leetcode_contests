// sorting + simulation

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int ans = 0, cnt = 0;
        for(int i = cost.size() - 1; i >= 0; i--) {
            if(cnt < 2) {
                ans += cost[i];
                cnt++;
            } else if(cnt == 2) {
                cnt = 0;
            }
        }
        return ans;
    }
};
