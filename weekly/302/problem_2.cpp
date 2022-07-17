class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for(int num : nums) {
            int tmp = num, sum = 0;
            while(tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            m[sum].push_back(num);
        }
        
        int ans = 0;
        for(auto kv : m) {
            int n = kv.second.size();
            if(n < 2)
                continue;
            sort(kv.second.begin(), kv.second.end());
            ans = max(ans, kv.second[n - 1] + kv.second[n - 2]);
        }
        return ans == 0 ? -1 : ans;
    }
};
