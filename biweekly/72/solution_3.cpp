// https://leetcode.com/problems/maximum-split-of-positive-even-integers/discuss/1783397/C%2B%2B-Space-O(1)-Solution-with-Comments

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        long long lastEven = 0;
        if(finalSum % 2) return {};
        while(finalSum) {
            // Start of with the lowest even number
            lastEven += 2;
            if(finalSum - lastEven <= lastEven) {
                // If the final sum is smaller than the current even number,
                // that means the remainder will only be the take numbers
                vector<long long> ans;
                for(int i = 2; i < lastEven; i += 2) {
                    ans.push_back(i);
                }
                ans.push_back(finalSum);
                return ans;
            } else {
                finalSum -= lastEven;
            }
        }
        return {};
    }
};
