class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> a(26, -1);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(a[s[i] - 'a'] == -1)
                a[s[i] - 'a'] = i;
            else
                a[s[i] - 'a'] = i - a[s[i] - 'a'] - 1;
        }
        for(int i = 0; i < 26; i++) {
            if(a[i] != -1 && a[i] != distance[i])
                return false;
        }
        return true;
    }
};
