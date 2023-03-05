// runtime error (integer overflow of long long)

class Solution {
public:
    int findValidSplit(vector<int>& A) {
        int n = A.size();
        vector<long long> p(n), s(n), gcds(n);
        p[0] = A[0];
        for(int i = 1; i < n; i++)
            p[i] = p[i - 1] * A[i - 1];
        s[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; i--)
            s[i] = s[i + 1] * A[i + 1];
        for(int i = 0; i < n; i++)
            gcds[i] = gcd(p[i], s[i]);
        
        int ans = 0;
        long long target = 1;
        bool found = false;
        for(int i = 0; i < n; i++) {
            if(gcds[i] == target) {
                ans = i;
                found = true;
                break;
            }
        }
        return found ? ans : -1;
    }
};

// WA when product is too large
class Solution {
public:
    int findValidSplit(vector<int>& A) {
        int n = A.size();
        vector<unsigned long long> p(n), s(n), gcds(n);
        p[0] = A[0];
        for(int i = 1; i < n; i++)
            p[i] = p[i - 1] * A[i];
        s[n - 1] = A[n - 1];
        for(int i = n - 2; i >= 0; i--)
            s[i] = s[i + 1] * A[i];
        for(int i = 0; i < n - 1; i++) {
            gcds[i] = gcd(p[i], s[i + 1]);
        }
        
        int ans = 0;
        unsigned long long target = 1;
        bool found = false;
        for(int i = 0; i < n - 1; i++) {
            if(gcds[i] == target) {
                ans = i;
                found = true;
                break;
            }
        }
        return found ? ans : -1;
    }
    
private:
    unsigned long long gcd(unsigned long long a, unsigned long long b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
};
