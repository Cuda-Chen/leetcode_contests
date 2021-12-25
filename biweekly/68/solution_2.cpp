// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/discuss/1646621/c%2B%2B-solution
// hash map and visited

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> ss(begin(supplies), end(supplies));
        bool flag = true;
        int n = recipes.size();
        vector<int> visited(n, false);
        vector<string> ans;
        
        while(flag) {
            flag = false;
            for(int i = 0; i < n; i++) {
                if(visited[i]) continue;
                bool t = true;
                for(string &s : ingredients[i]) {
                    if(!ss.count(s)) {
                        t = false;
                        break;
                    }
                }
                if(t) {
                    flag = true;
                    ss.insert(recipes[i]);
                    visited[i] = true;
                    ans.push_back(recipes[i]);
                }
            }
        }
        
        return ans;
    }
};
