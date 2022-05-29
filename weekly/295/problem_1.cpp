class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> s_cnt(26, 0), t_cnt(26, 0);
        for(char c : s)
            s_cnt[c - 'a']++;
        for(char c : t)
            t_cnt[c - 'a']++;
        
        int ans = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(t_cnt[i] == 0)
                s_cnt[i] = 0;
            else
                s_cnt[i] /= t_cnt[i];
        }
        for(char c : t)
            ans = min(ans, s_cnt[c - 'a']);
        return ans;
    }
};
