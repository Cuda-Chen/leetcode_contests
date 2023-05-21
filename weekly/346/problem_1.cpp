class Solution {
public:
    int minLength(string s) {
        while(s.size() > 2) {
            int idx1 = -1, idx2 = -1;
            bool flag = false;
            for(int i = 0; i < s.size() - 1; i++) {
                if((s[i] == 'A' && s[i + 1] == 'B') ||
                   (s[i] == 'C' && s[i + 1] == 'D')) {
                    idx1 = i;
                    idx2 = i + 1;
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                break;
            
            string tmp;
            for(int i = 0; i < s.size(); i++) {
                if(i == idx1 || i == idx2)
                    continue;
                
                tmp += s[i];
            }
            s = tmp;
            //cout << s << endl;
        }
        if(s.size() == 2 && ((s[0] == 'A' && s[1] == 'B') || (s[0] == 'C' && s[1] == 'D')))
            return 0;
        return s.size();
    }
};
