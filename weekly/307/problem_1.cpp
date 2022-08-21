// prefix sum
// WA in test case:
/* 1
1
[1,1,1,1]
[1,1,1,50] */

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans = 0;
        ans += (initialEnergy > accumulate(begin(energy), end(energy), 0)
                ? 0
                : abs(initialEnergy - accumulate(begin(energy), end(energy), 0)) + 1);
        int ex = initialExperience;
        for(int i = 0; i < experience.size(); i++) {
            cout << ex << " " << ans << endl;
            if(ex <= experience[i])
                ans += abs(ex - experience[i]) + 1;
            ex += experience[i];
        }
        return ans;
    }
};
