// https://leetcode.com/problems/split-the-array-to-make-coprime-products/solutions/3258070/count-primes/

class Solution {
public:
    int findValidSplit(vector<int>& A) {
        unordered_map<int, int> l, r;
        for(int n : A) {
            for(int f : factorize(n))
                r[f]++;
        }
        for(int i = 0; i < A.size() - 1; i++) {
            for(int f : factorize(A[i])) {
                if(--r[f] == 0)
                    l.erase(f);
                else
                    l[f]++;
                if(l.empty())
                    return i;
            }
        }
        return -1;
    }
    
private:
    vector<int> factorize(int n) {
        vector<int> ans;
        for(int i = 2; i <= 1000; i += 1 + (i % 2)) {
            if(n % i == 0) {
                ans.push_back(i);
                while(n % i == 0)
                    n /= i;
            }
        }
        if(n > 1)
            ans.push_back(n);
        return ans;
    }
};
