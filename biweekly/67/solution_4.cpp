// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/discuss/1623386/C%2B%2B-or-Map-lessstring-setlessscoregreatergreater-or-Easy
// Map <score, set<string>>

class SORTracker {
public:
    map<int, set<string>> wordsMap;
    int called;
    
    SORTracker() {
        called = 1;
    }
    
    void add(string name, int score) {
        wordsMap[score].insert(name);
    }
    
    string get() {
        int total = 0;
        string ans = "";
        for(auto it = wordsMap.rbegin(); it != wordsMap.rend(); it++) {
            if(total + it->second.size() >= called) {
                int rem = called - total;
                std::set<string>::iterator itD = it->second.begin();
                std::advance(itD, rem - 1);
                ans = *itD;
                break;
            } else {
                total += it->second.size();
            }
        }
        called++;
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
