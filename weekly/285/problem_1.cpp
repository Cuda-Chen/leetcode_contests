// brute-force
// AC

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
        }

        int ans = 0;
        for(int i = 0; i < temp.size(); i++) {
            if(i == 0 || i == temp.size() - 1)
                continue;
            if((temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) ||
               (temp[i] < temp[i - 1] && temp[i] < temp[i + 1]))
                ans++;
        }

        return ans;
    }
};
