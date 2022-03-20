// https://leetcode.com/problems/count-collisions-on-a-road/discuss/1865557/C%2B%2B-With-Logic-And-Intuition

class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, n = directions.size(), i = 0, carsFromRight = 0;
        while(i < n && directions[i] == 'L') i++; // skipping all the cars going to left from beginning as they will never collide
        for(; i < n; i++) {
            if(directions[i] == 'R') carsFromRight++;
            else {
                ans += (directions[i] == 'S') ? carsFromRight : carsFromRight + 1;
                carsFromRight = 0;
            }
        }
        return ans;
    }
};
