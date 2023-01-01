// https://www.geeksforgeeks.org/distinct-prime-factors-of-array-product/
// hash table

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> m;
        for(int num : nums) {
            int tmp = sqrt(num);
            for(int j = 2; j <= tmp; j++) {
                if(num % j == 0) {
                    m.insert(j);
                    while(num % j == 0)
                        num /= j;
                }
            }
            if(num > 1)
                m.insert(num);
        }
        return m.size();
    }
};
