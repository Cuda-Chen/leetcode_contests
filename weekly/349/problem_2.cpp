class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        bool flag = true;
        for(int i = 0; i < n; i++) {
            if(s[i] != 'a') {
                flag = false;
                break;
            }
        }
        if(flag) {
            s.back() = 'z';
            return s;
        }
        
        int l = 0, r = 0;
        while(l < n) {
            if(s[l] == 'a')
                l++;
            else
                break;
        }
        r = l;
        while(r < n) {
            if(s[r] != 'a')
                r++;
            else
                break;
        }
        for(int i = l; i < r; i++)
            s[i] -= 1;
        return s;
    }
};
