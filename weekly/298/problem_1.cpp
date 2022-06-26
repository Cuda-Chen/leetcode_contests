class Solution {
public:
    string greatestLetter(string s) {
        vector<int> u(26, 0), l(26, 0);
        for(char c : s) {
            int a = c - 'A';
            int b = c - 'a';
            if(a >= 0 && a < 26)
                u[a]++;
            if(b >= 0 && b < 26)
                l[b]++;
        }
        int tmp = 0;
        bool flag = false;
        for(int i = 0; i < 26; i++) {
            if(u[i] && l[i]) {
                flag = true;
                tmp = i;
            }
        }
        char ans = (char)(tmp + 'A');
        return flag ? string(1, ans) : "";
    }
};
