// segment tree
// https://leetcode.com/problems/range-sum-query-immutable/submissions/584279093/

class segment_tree {
public:
    segment_tree(vector<int> &nums) : st(nums.size() * 4), size(nums.size()) {
        init(1, 0, nums.size() - 1, nums);
    }
                                                                
    int query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
    
private:
    vector<int> st;
    int size;
    
    void init(int id, int l, int r, vector<int> &nums) {
        if(l == r) {
            st[id] = nums[l];
            return;
        }
        int m = l + (r - l) / 2;
        init(id * 2, l, m, nums);
        init(id * 2 + 1, m + 1, r, nums);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
                                                                
    int query(int id, int l, int r, int L, int R) {
        if(R < l || L > r)
            return 0;
        if(L <= l && r <= R)
            return st[id];
        int m = l + (r - l) / 2;
        return query(id * 2, l, m, L, R) + query(id * 2 + 1, m + 1, r, L, R);
    }                                                                                                            
};

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        vector<int> arr(words.size());
        for(int i = 0; i < words.size(); i++) {
            string w = words[i];
            char a = w[0], b = w.back();
            if(vowels.count(a) && vowels.count(b))
                arr[i] = 1;
        }
        
        segment_tree st(arr);
        vector<int> ans;
        for(auto q : queries) {
            ans.push_back(st.query(q[0], q[1]));
        }
        return ans;
    }
};
