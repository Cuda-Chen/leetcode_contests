class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        int n = word1.size();
        for(int i = 0; i < n; i++) {
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(abs(cnt1[i] - cnt2[i]) >= 4)
                return false;
        }
        
        return true;
    }
};
