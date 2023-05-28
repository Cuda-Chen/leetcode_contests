class Solution {
public:
    string removeTrailingZeros(string s) {
        int n = s.size();
        int r = n - 1;
        while(s[r] == '0')
            r--;
        return s.substr(0, r + 1);
    }
};
