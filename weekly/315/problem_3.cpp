// math

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        int a = 0;
        while(a <= num) {
            int r = 0;
            int a_cpy = a;
            while(a_cpy) {
                r = r * 10 + a_cpy % 10;
                a_cpy /= 10;
            }
            if((a + r) == num)
                return true;
            a++;
        }
        return false;
    }
};
