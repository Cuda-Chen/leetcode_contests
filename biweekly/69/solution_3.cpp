// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/discuss/1675428/C%2B%2B-or-Map-or-Easy-Solution
// map

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> mp;
        for(auto w : words)
            mp[w]++;
        
        int ans = 0;
        bool ok = false;
        for(auto i : mp) {
            string s = i.first;
            reverse(s.begin(), s.end());
            
            if(s == i.first) {
                if(i.second > 1) {
                    if(i.second & 1) {
                        ans += (i.second - 1) * 2;
                        ok = true;
                    } else {
                        ans += i.second * 2;
                    }
                } else {
                    ok = true;
                }
            } else {
                if(mp.count(s)) {
                    int mn = min(i.second, mp[s]);
                    ans += mn * 2;
                }
            }
        }
        if(ok) ans += 2;
        
        return ans;
    }
};
