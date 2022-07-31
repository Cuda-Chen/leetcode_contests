class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool flag = false;
        while(!flag) {
            int tmp = INT_MAX;
            for(int i = 0; i < n; i++) {
                if(nums[i] > 0 && nums[i] < tmp)
                    tmp = nums[i];
            }
            if(tmp == INT_MAX)
                break;
            ans++;
            for(int i = 0; i < n; i++)
                nums[i] -= tmp;
        }
        return ans;
    }
};
