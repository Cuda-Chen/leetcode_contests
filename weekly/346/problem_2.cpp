class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int l, r;
        if(n & 1) {
            l = r = n / 2;
            while(l >= 0 && r < n) {
                if(s[l] != s[r]) {
                    int tmp = min(s[l], s[r]);
                    s[l] = tmp;
                    s[r] = tmp;
                }
                l--;
                r++;
            }
        } else {
            r = n / 2;
            l = r - 1;
            while(l >= 0 && r < n) {
                if(s[l] != s[r]) {
                    int tmp = min(s[l], s[r]);
                    s[l] = tmp;
                    s[r] = tmp;
                }
                l--;
                r++;
            }
        }
        return s;
    }
};
