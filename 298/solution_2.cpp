// https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/discuss/2168323/JavaC%2B%2BPython-Enumerate-from-1-to-10
// Enumerate from 1 to 10

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num == 0)
            return 0;
        for(int i = 1; i * k <= num && i <= 10; i++)
            if(k * i % 10 == num % 10)
                return i;
        return -1;
    }
};
