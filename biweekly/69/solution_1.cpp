// naive

class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> temp;
        istringstream iss(title);
        string word;
        while(iss >> word) {
            transform(word.begin(), word.end(), word.begin(), [](char c) {
                return tolower(c);
            });
            temp.emplace_back(word);
        }
        
        string ans = "";
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i].size() < 3) ans += temp[i];
            else {
                temp[i][0] = toupper(temp[i][0]);
                ans += temp[i];
            }
            if(i != temp.size() - 1)
                ans += " ";
        }
        
        return ans;
    }
};
