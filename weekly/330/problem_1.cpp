// brute-force

class Solution {
public:
    int distinctIntegers(int n) {
        vector<int> tmp(n + 1);
        tmp[n] = 1;
        queue<int> q{{n}};
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(int i = 1; i <= t; i++) {
                if(t % i == 1) {
                    tmp[i] = 1;
                    q.push(i);
                }
            }
        }
        int ans = accumulate(begin(tmp), end(tmp), 0);
        return ans;
    }
};
