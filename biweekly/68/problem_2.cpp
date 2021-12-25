// WA

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> s;
        for(auto recipe : recipes)
            s.insert(recipe);
        for(auto supply : supplies)
            s.insert(supply);
        
        vector<string> ans;
        for(int i = 0; i < recipes.size(); i++) {
            bool flag = true;
            for(auto ingredient : ingredients[i]) {
                if(!s.count(ingredient)) {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(recipes[i]);
        }
        
        return ans;
    }
};
