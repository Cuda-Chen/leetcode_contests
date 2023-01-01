class Solution {
public:
    int countDigits(int num) {
        int tmp = num, ans = 0;
        while(tmp) {
            int a = tmp % 10;
            if(num % a == 0)
                ans++;
            tmp /= 10;
        }
        return ans;
    }
};
