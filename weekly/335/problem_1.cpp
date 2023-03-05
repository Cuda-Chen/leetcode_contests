// simulation

class Solution {
public:
    int passThePillow(int n, int time) {
        int cur = 1, d = 1;
        for(int i = 1; i <= time; i++) {
            if(cur == 1)
                d = 1;
            if(cur == n)
                d = -1;
            cur += d;
        }
        return cur;
    }
};
