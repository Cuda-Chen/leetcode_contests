// naive

class Solution {
public:
    string largestGoodInteger(string s) {
        int n = s.size();
        string ans;
        for(int i = 0; i < n; i++) {
            if(i - 1 < 0 || i + 1 >= n)
                continue;
            if(s[i - 1] == s[i] && s[i] == s[i + 1]) {
                if(ans.empty() || s[i] > ans[0])
                    ans = string(3, s[i]);
            }
        }
        return ans;
    }
};
