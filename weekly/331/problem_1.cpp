// priority queue

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(auto g : gifts)
            q.push(g);
        while(k--) {
            int t = q.top();
            q.pop();
            t = (int)sqrt(t);
            q.push(t);
        }
        long long ans = 0;
        while(!q.empty()) {
            int t = q.top();
            ans += t;
            q.pop();
        }
        return ans;
    }
};
