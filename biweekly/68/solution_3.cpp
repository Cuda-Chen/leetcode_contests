// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/discuss/1646594/Left-to-right-and-right-to-left
// two-pass

class Solution {
public:
    bool canBeValid(string s, string locked) {
        auto validate = [&](char open) {
            int bal = 0, wild = 0, sz = s.size();
            int start = open == '(' ? 0 : sz - 1, dir = open == '(' ? 1 : -1;
            for(int i = start; i >= 0 && i < sz && wild >= 0; i += dir) {
                if(locked[i] == '1')
                    bal += s[i] == open ? 1 : -1;
                else
                    ++wild;
                if(bal < 0) {
                    --wild;
                    bal = 0;
                }
            }
            return bal <= wild;
        };
        return s.size() % 2 == 0 && validate('(') && validate(')');
    }
};
