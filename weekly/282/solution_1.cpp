class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto w : words) {
            bool flag = true;
            for(int i = 0; i < pref.size(); i++) {
                if(w[i] != pref[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};
