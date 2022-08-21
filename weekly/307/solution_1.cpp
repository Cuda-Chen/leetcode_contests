// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/discuss/2456641/C%2B%2B-O(N)

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int time = 0;
        
        for(int i = 0; i < n; i++) {
            int d1 = initialEnergy - energy[i], d2 = initialExperience - experience[i];
            time += (d1 <= 0 ? abs(d1) + 1 : 0);
            time += (d2 <= 0 ? abs(d2) + 1 : 0);
            initialEnergy = max(initialEnergy - energy[i], 1);
            initialExperience += experience[i] + (d2 <= 0 ? abs(d2) + 1 : 0);
        }
        time -= (initialEnergy - 1);
        
        return max(time, 0);
    }
};
