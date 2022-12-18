// hash map

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> m;
        for(auto w : words) {
            int num = 0;
            for(char c : w)
                num |= 1 << (c - 'a');
            m[num]++;
        }
        int ans = 0;
        for(auto kv : m) {
            ans += nChoosek(kv.second, 2);
        }
        return ans;
    }
    
private:
    int nChoosek(int n, int k) {
    if (k > n) 
        return 0;
    if (k * 2 > n) 
        k = n - k;
    if (k == 0) 
        return 1;

    int result = n;
    for(int i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}
};
