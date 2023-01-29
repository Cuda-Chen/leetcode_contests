// https://leetcode.com/problems/count-increasing-quadruplets/solutions/3111998/c-easy-o-n-2-direct-do-what-given-in-problem/?q=C%2B%2B&orderBy=most_relevant
// prefix/suffix sum

class Solution {
public:
    long long countQuadruplets(vector<int>& a) {
        // loop on j and k
        int n = a.size();
        for(auto &x : a)
            x--;
        vector<vector<int>> pre_less(n, vector<int>(n));
        vector<vector<int>> suff_greater(n, vector<int>(n));
        
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                if(a[i] < j)
                    pre_less[i][j]++;
                if(i)
                    pre_less[i][j] += pre_less[i - 1][j];
            }
        }
        
        for(int j = 0; j < n; j++) {
            for(int i = n - 1; i >= 0; i--) {
                if(a[i] > j)
                    suff_greater[i][j]++;
                if(i != n - 1)
                    suff_greater[i][j] += suff_greater[i + 1][j];
            }
        }
        
        long long ans = 0;
        for(int j = 1; j < n - 2; j++) {
            for(int k = j + 1; k < n - 1; k++) {
                if(a[k] > a[j])
                    continue;
                ans += 1LL * pre_less[j - 1][a[k]] * suff_greater[k + 1][a[j]];
            }
        }
        
        return ans;
    }
};
