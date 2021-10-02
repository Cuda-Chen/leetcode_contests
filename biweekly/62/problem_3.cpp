// https://aaronice.gitbook.io/lintcode/two_pointers/longest-repeating-character-replacement
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        vector<int> cnt(26);
        int maxCount = 0;
        int maxLength = 0;
        int l = 0;
        
        for(int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'A'] += 1;
            maxCount = max(maxCount, cnt[s[r] - 'A']);
            while(r - l + 1 - maxCount > k) {
                cnt[s[l] - 'A'] -= 1;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};
