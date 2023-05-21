// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/solutions/3547015/o-n-easy-solution-recursion-c-java-python/

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int tmp = i * i;
            string s = to_string(tmp);
            if(check(0, s, i)) {
                ans += tmp;
            }
        }
        return ans;
    }
    
private:
    bool check(int idx, string &s, int target) {    
        if(idx == s.size()) {
            if(target == 0)
                return true;
            else
                return false;
        }
        if(target < 0)
            return false;
        for(int i = idx; i < s.size(); i++) {
            string x = s.substr(idx, i + 1 - idx);
            int y = stoi(x);
            if(check(i + 1, s, target - y))
                return true;
        }
        return false;
    }
};
