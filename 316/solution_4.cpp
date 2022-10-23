// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/discuss/2734189/C%2B%2BPython-Sort-odds-and-evens
// sort odds and evens

class Solution {
public:
    long long makeSimilar(vector<int>& A, vector<int>& B) {
        vector<vector<int>> AA(2), BB(2);
        for(int a : A)
            AA[a % 2].push_back(a);
        for(int b : B)
            BB[b % 2].push_back(b);
        sort(AA[0].begin(), AA[0].end());
        sort(AA[1].begin(), AA[1].end());
        sort(BB[0].begin(), BB[0].end());
        sort(BB[1].begin(), BB[1].end());
        
        long long ans = 0;
        for(int i = 0; i < AA[0].size(); i++)
            ans += abs(AA[0][i] - BB[0][i]) / 2;
        for(int i = 0; i < AA[1].size(); i++)
            ans += abs(AA[1][i] - BB[1][i]) / 2;
        return ans / 2;
    }
};
