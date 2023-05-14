class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans, arr(n);
        int tmp = 0;
        unordered_map<int, unordered_set<int>> m; // {color, indices}
        for(auto q : queries) {
            int idx = q[0], color = q[1];
            // update adjacent elements
            if(arr[idx] != 0) {
                int c = arr[idx];
                m[c].erase(idx);
                if(idx > 0 && m[c].count(idx - 1))
                    tmp--;
                if(idx < n && m[c].count(idx + 1))
                    tmp--;
            }
            if(tmp < 0)
                tmp = 0;
            
            // count adjacent elements
            arr[idx] = color;
            m[color].insert(idx);
            if(idx > 0 && m[color].count(idx - 1))
                tmp++;
            if(idx < n && m[color].count(idx + 1))
                tmp++;
            
            ans.push_back(tmp);
        }
        return ans;
    }
};
