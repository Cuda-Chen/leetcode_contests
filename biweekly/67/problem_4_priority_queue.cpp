// TLE

class SORTracker {
public:
    SORTracker() {
        cnt = 0;
    }
    
    void add(string name, int score) {
        arr.push_back({name, score});
    }
    
    string get() {
        cnt++;
        priority_queue<Attr> q(arr.begin(), arr.end());
        for(int i = 0; i < cnt - 1; i++)
            q.pop();
        return q.top().name;
    }
    
private:
    struct Attr {
        string name;
        int score;
        
        bool operator<(const Attr &a) const {
            if(score == a.score)
                return name > a.name;
            return score < a.score;
        }
    };
    
    vector<Attr> arr;
    int cnt;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
