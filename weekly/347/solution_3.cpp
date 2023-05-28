// https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/solutions/3570380/java-c-python-easy-and-concise/
// prefix/suffix

class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        for(int i = 1, n = s.size(); i < n; i++) {
            if(s[i] != s[i - 1])
                ans += min(i, n - i);
        }
        return ans;
    }
};
