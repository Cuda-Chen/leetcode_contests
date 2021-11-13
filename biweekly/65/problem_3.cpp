// MLE
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int, int> beauty_table; // {price, max beauty of the price}
        for(vector<int> item : items) {
            if(!beauty_table.count(item[0]))
                beauty_table[item[0]] = item[1];
            else if(beauty_table[item[0]] < item[1])
                beauty_table[item[0]] = item[1];
        }
        
        vector<int> prefix_max(*max_element(begin(queries), end(queries)) + 1, 0);
        for(int i = 1; i < prefix_max.size(); i++) {
            prefix_max[i] = max(prefix_max[i - 1], beauty_table[i]);
        }
        
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); i++) {
            ans[i] = prefix_max[queries[i]];
        }
        
        return ans;
    }
};
