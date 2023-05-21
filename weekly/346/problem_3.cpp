// WA

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int tmp = i * i;
            string s = to_string(tmp);
            cout << i << " " << tmp << endl;
            if(f(s, i)) {
                //cout << i << " " << tmp << endl;
                ans += tmp;
            }
        }
        return ans;
    }
    
private:
    bool f(const string &s, int target) {
        if(target == 0)
            return s.empty();
        if(target < 0)
            return false;
        if(s.size() == 1)
            return stoi(s) == target;
        bool ret = false;
        for(int i = 1; i <= s.size(); i++) {
            int tmp = stoi(s.substr(0, i));
            //cout << tmp << " ";
            ret |= f(s.substr(i), target - tmp);
        }
        //cout << endl;
        return ret;
    }
};
