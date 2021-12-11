// WA
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        int n = bombs.size();
        for(int i = 0; i < n; i++) {
            int cnt = 1;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                if(sqrt(pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2)) <= bombs[i][2])
                    cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
