class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
        vector<int> v;
        for(int i = l; i <= r; i++) {
            if(isPrime(i))
                v.push_back(i);
        }
        
        if(v.size() < 2)
            return {-1, -1};
        else if(v.size() == 2)
            return v;
        int idx = -1;
        int diff = INT_MAX;
        for(int i = 0; i < v.size() - 1; i++) {
            int a = v[i], b = v[i + 1];
            int tmp = b - a;
            if(tmp < diff) {
                diff = tmp;
                idx = i;
            }
        }
        return {v[idx], v[idx + 1]};
    }
    
private:
    // https://stackoverflow.com/a/14418599
    bool isPrime(int a) {
        if(a < 2)
            return false;
        if(a == 2)
            return true;
        if(a % 2 == 0)
            return false;
        for(int i = 3; (i * i) <= a; i += 2) {
            if(a % i == 0)
                return false;
        }
        return true;
    }
};
