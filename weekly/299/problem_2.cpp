// Fibonacci-like
// consider big-num calculation

class Solution {
public:
    unsigned long long countHousePlacements(int n) {
        int kMod = 1e9 + 7;
        int n1 = 1, n2 = 2;
        int tmp;
        if(n == 1)
            tmp = n2;
        
        for(int i = 2; i <= n; i++) {
            tmp = n1 + n2;
            n1 = n2;
            n2 = tmp;
            tmp %= kMod;
            n1 %= kMod;
            n2 %= kMod;
        }

        return tmp * tmp;
    }
};
