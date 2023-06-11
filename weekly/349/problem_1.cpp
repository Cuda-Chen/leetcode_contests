class Solution {
public:
    int findNonMinOrMax(vector<int>& A) {
        int a = *min_element(begin(A), end(A));
        int b = *max_element(begin(A), end(A));
        for(int num : A) {
            if(num != a && num != b)
                return num;
        }
        return -1;
    }
};
