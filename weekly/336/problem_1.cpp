class Solution {
public:
    int vowelStrings(vector<string>& words, int l, int r) {
        unordered_set<char> m{'a', 'e', 'i', 'o', 'u'};
        int ans = 0;
        for(int i = l; i <= r; i++) {
            if(m.count(words[i][0]) && m.count(words[i].back()))
               ans++;
        }
        return ans;
    }
};
