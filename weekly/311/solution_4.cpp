// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/discuss/2590148/Trie
// Trie

struct Trie {
    Trie *ch[26] = {nullptr};
    int cnt = 0;
    
    void insert(string &w, int i = 0) {
        auto n = this;
        for(auto c : w) {
            if(!n->ch[c - 'a'])
                n->ch[c - 'a'] = new Trie();
            n = n->ch[c - 'a'];
            ++n->cnt;
        }
    }
    
    int count(string &w, int i = 0) {
        return cnt + (i == w.size() ? 0 : ch[w[i] - 'a']->count(w, i + 1));
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for(auto &w : words)
            t.insert(w);
        vector<int> ans;
        for(auto &w : words)
            ans.push_back(t.count(w));
        return ans;
    }
};
