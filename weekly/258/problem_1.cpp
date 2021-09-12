class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = -1;
        string ans;
        int n = word.size();
        for(int i = 0; i < n; i++) {
            if(word[i] == ch) {
                idx = i;
                break;
            }
        }
        
        for(int i = idx; i >= 0; i--)
            ans += word[i];
        for(int i = idx + 1; i < n; i++)
            ans += word[i];
        
        return ans;
    }
};
