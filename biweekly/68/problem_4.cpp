// TLE
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        vector<int> v;
        v.push_back(1);
        int carry = 0;
        for(int i = left; i <= right; i++) {
            carry = 0;
            for(int &x : v) {
                int m = (x * i) + carry;
                x = (m % 10);
                carry = m / 10;
            }
            while(carry) {
                v.emplace_back(carry % 10);
                carry /= 10;
            }
        }
        
        // Get trailing zero
        size_t idx = 0;
        int cnt = 0;
        while(v[idx] == 0) {
            cnt++;
            idx++;
        }
        
        string ans = "";
        size_t remain = v.size() - cnt;
        if(remain > 10) {
            for(int i = v.size() - 1; i >= v.size() - 5; i--) {
                ans += to_string(v[i]);
            }
            ans += "...";
            for(int i = cnt + 5 - 1; i >= cnt; i--) {
                ans += to_string(v[i]);
            }
            ans += "e";
            ans += to_string(cnt);
        } else {
            for(int i = v.size() - 1; i >= cnt; i--) {
                ans += to_string(v[i]);
            }
            ans += "e";
            ans += to_string(cnt);
        }
        
        return ans;
    }
};
