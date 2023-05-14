class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> cnt(n);
        
        int tmp = 1, idx = 0;
        while(true) {
            cnt[idx]++;
            if(cnt[idx] >= 2)
                break;
            idx += (k * tmp);
            idx %= n;
            tmp++;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(cnt[i] == 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};
