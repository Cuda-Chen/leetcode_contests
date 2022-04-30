// brute-force

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for(auto w : words) {
            bool flag = true;
            for(int i = 0; i < w.size(); i++) {
                if(s[i] != w[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
};
