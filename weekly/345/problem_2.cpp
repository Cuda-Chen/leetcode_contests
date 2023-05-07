class FrequencyTracker {
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int tmp = m[number];
        m[number]++;
        cnt[m[number]]++;
        cnt[tmp]--;
    }
    
    void deleteOne(int number) {
        if(m[number] > 0) {
            cnt[m[number]]--;
            m[number]--;
            cnt[m[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return cnt.count(frequency) && cnt[frequency] > 0;
    }
    
private:
    unordered_map<int, int> m; // {num, cnt}
    unordered_map<int, int> cnt; // {cnt, freq}
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
