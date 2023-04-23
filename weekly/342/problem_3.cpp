// bucket sort

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int buckets = 101; // 50 - (50) + 1 = 101
        vector<int> cnt(buckets); // val + 50 = idx
        vector<int> ans;
        
        for(int i = 0; i < k; i++)
            cnt[nums[i] + 50]++;
        int smallest = x;
        for(int idx = 0; idx < buckets; idx++) {
            if(cnt[idx] > 0)
                smallest -= cnt[idx];
            if(smallest <= 0) {
                if(idx - 50 > 0)
                    ans.push_back(0);
                else
                    ans.push_back(idx - 50);
                break;
            }
        }
        
        for(int i = k; i < n; i++) {
            cnt[nums[i - k] + 50]--;
            cnt[nums[i] + 50]++;
            int smallest = x;
            for(int idx = 0; idx < buckets; idx++) {
                if(cnt[idx])
                    smallest -= cnt[idx];
                if(smallest <= 0) {
                    if(idx - 50 > 0)
                        ans.push_back(0);
                    else
                        ans.push_back(idx - 50);
                    break;
                }
            }
        }
        
        return ans;
    }
};
