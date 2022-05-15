// TLE in hidden test case

class CountIntervals {
public:
    CountIntervals() {

    }

    void add(int left, int right) {
        auto it = intervals.begin();
        while(it != intervals.end() && (*it)[0] < left)
            it++;
        intervals.insert(it, {left, right});

        vector<vector<int>> ans;
        for(auto i : intervals) {
            if(ans.empty() || i[0] > ans.back()[1])
                ans.push_back(i);
            else
                ans.back()[1] = max(ans.back()[1], i[1]);
        }
        intervals = std::move(ans);
    }

    int count() {
        int ans = 0;
        for(auto i : intervals)
            ans += (i[1] - i[0] + 1);
        return ans;
    }

private:
    vector<vector<int>> intervals;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
