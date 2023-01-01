// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/solutions/2977270/greedy/
// greedy

class Solution {
public:
    int minimumPartition(string s, int k) {
        long long n = 0, ans = 1;
        for(int i = 0; i < s.size(); i++) {
            if(n * 10 + (s[i] - '0') > k) {
                ans++;
                n = 0;
            }
            n = n * 10 + (s[i] - '0');
            if(n > k)
                return -1;
        }
        return ans;
    }
};
