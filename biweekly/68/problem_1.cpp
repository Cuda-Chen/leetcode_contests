class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(string sentence : sentences) {
            int cnt = 0;
            for(char c : sentence) {
                if(c == ' ')
                    cnt++;
            }
            ans = max(ans, cnt + 1);
        }
        return ans;
    }
};
