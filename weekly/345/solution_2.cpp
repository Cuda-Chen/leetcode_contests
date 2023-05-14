// https://leetcode.com/problems/neighboring-bitwise-xor/solutions/3522095/java-c-python-sum-is-even/
// sum is even

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0) % 2 == 0;
    }
};
