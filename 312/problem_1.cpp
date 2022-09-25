// sort by heights

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<vector<int>> tmp;
        for(int i = 0; i < heights.size(); i++)
            tmp.push_back({heights[i], i});
        sort(tmp.rbegin(), tmp.rend());
        vector<string> ans;
        for(auto t : tmp)
            ans.push_back(names[t[1]]);
        return ans;
    }
};
