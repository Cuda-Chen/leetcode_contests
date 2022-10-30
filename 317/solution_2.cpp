// https://leetcode.com/problems/most-popular-video-creator/discuss/2758053/One-HashMap-No-Sorting
// one hashmap

struct video {
    long sum = 0;
    string small;
    int max_view = 0;
};

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& ids, vector<int>& views) {
        unordered_map<string, video> mp;
        long cnt = 0;
        
        for(int i = 0; i < size(c); i++) {
            if(!mp.count(c[i])) {
                mp[c[i]] = {views[i], ids[i], views[i]};
                cnt = max(cnt, mp[c[i]].sum);
                continue;
            }
            
            mp[c[i]].sum += views[i];
            if(mp[c[i]].max_view < views[i] || mp[c[i]].max_view == views[i] && ids[i] < mp[c[i]].small) {
                mp[c[i]].max_view = views[i];
                mp[c[i]].small = ids[i];
            }
            
            cnt = max(cnt, mp[c[i]].sum);
        }
        
        vector<vector<string>> ans;
        for(auto &r : mp)
            if(r.second.sum == cnt)
                ans.push_back({r.first, r.second.small});
        return ans;
    }
};
