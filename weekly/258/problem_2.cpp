// GCD
// Reference:
// https://ideone.com/aDJXNO
// https://stackoverflow.com/questions/32685540/why-cant-i-compile-an-unordered-map-with-a-pair-as-key

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<size_t, long long> map; // ratio, count
        for(auto rect : rectangles) {
            int i = rect[0], j = rect[1];
            int GCD = std::gcd(i, j);
            if(GCD != 1) {
                i /= GCD;
                j /= GCD;
            }
            if(map.count(key(i, j)))
                map[key(i, j)] += 1;
            else
                map.emplace(key(i, j), 1);
        }
        cout << "GCD";
        
        long long ans = 0;
        for(auto elem : map) {
            //cout << elem.second << " " << nCr(elem.second, 2) << endl;
            ans += nCr(elem.second, 2);
        }
        cout << "combination";
        
        return ans;
    }
    
private:
    inline size_t key(int i, int j) { return (size_t) i << 32 | (unsigned int) j; }
    long long kMod = 1e9 + 7;
    
    long long nCr(long long n, long long k) {
        if (k > n) return 0;
        if (k * 2 > n) /*return*/ k = n-k;  //remove the commented section
        if (k == 0) return 1;
 
        long long result = n;
        for(long long i = 2; i <= k; ++i ) {
            result *= (n-i+1);
            result /= i;
        }   
        return result;
    }
};
