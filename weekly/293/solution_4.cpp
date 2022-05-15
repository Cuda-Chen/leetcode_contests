// https://leetcode.com/problems/count-integers-in-intervals/discuss/2039706/Merge-Intervals
// merge inetervals

class CountIntervals {
public:
    CountIntervals() {

    }
    
    void add(int left, int right) {
        auto it = m.upper_bound(left);
        if(it != begin(m)) {
            auto p = prev(it);
            if(p->second >= left) {
                left = p->first;
                right = max(right, p->second);
                cnt -= p->second - p->first + 1;
                m.erase(p);
            }
        }
        for(; it != end(m) && it->first <= right; m.erase(it++)) {
            right = max(right, it->second);
            cnt -= it->second - it->first + 1;
        }
        cnt += right - left + 1;
        m[left] = right;
    }
    
    int count() {
        return cnt;
    }
    
private:
    map<int, int> m;
    int cnt = 0;
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
