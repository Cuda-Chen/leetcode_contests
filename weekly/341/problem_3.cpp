// sliding window

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        if(n == 1)
            return 2;
        int ans = 0, idx = 0;
        while(idx < n) {
            if(word[idx] == 'a') {
                if(idx + 1 < n && word[idx + 1] == 'b') {
                    if(idx + 2 < n && word[idx + 2] == 'c') {
                        idx += 3;
                    } else {
                        ans += 1;
                        idx += 2;
                    }
                } else if(idx + 1 < n && word[idx + 1] == 'c') {
                    ans += 1;
                    idx += 2;
                } else {
                    ans += 2;
                    idx++;
                }
            } else if(word[idx] == 'b') {
                if(idx + 1 < n && word[idx + 1] == 'c') {
                    ans += 1;
                    idx += 2;
                } else {
                    ans += 2;
                    idx++;
                }
            } else if(word[idx] == 'c') {
                ans += 2;
                idx++;
            }
        }
        return ans;
    }
};
