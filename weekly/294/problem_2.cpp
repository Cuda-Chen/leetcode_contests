// sort + greedy

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n, 0);
        for(int i = 0; i < n; i++)
            diff[i] = capacity[i] - rocks[i];
        sort(diff.begin(), diff.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            cout << diff[i] << " ";
            if(diff[i] == 0) {
                ans++;
            } else if(diff[i] <= additionalRocks) {
                ans++;
                additionalRocks -= diff[i];
            }
        }
        return ans;
    }
};
