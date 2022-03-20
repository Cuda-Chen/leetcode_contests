// brute-force
// WA

class Solution {
public:
    int countCollisions(string s) {
        int ans = 0;
        int i = 0;
        // head
        {
            if(s[i] == 'R' && s[i + 1] == 'L') {
                ans += 2;
                s[i] = s[i + 1] = 'S';
            } else if(s[i] == 'R' && s[i + 1] == 'S') {
                ans++;
                s[i] = s[i + 1] = 'S';
            }
        }
        // body
        for(i = 1; i < s.size() - 1; i++) {
            if(s[i] == 'R' && s[i + 1] == 'L') {
                ans += 2;
                s[i] = s[i + 1] = 'S';
            } else if(s[i] == 'R' && s[i + 1] == 'S') {
                ans++;
                s[i] = s[i + 1] = 'S';
            } else if(s[i] == 'L' && s[i - 1] == 'R') {
                ans += 2;
                s[i] = s[i - 1] = 'S';
            } else if(s[i] == 'L' && s[i - 1] == 'S') {
                ans++;
                s[i] = s[i - 1] = 'S';
            }
        }
        // tail
        {
            if(s[i] == 'L' && s[i - 1] == 'R') {
                ans += 2;
                s[i] = s[i - 1] = 'S';
            } else if(s[i] == 'L' && s[i - 1] == 'S') {
                ans++;
                s[i] = s[i - 1] = 'S';
            }
        }
        return ans;
    }
};
