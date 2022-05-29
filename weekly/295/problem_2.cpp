class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans = "", s;
        vector<string> tmp;
        stringstream ss(sentence);
        while(getline(ss, s, ' '))
            tmp.push_back(s);
        
        for(auto a : tmp) {
            if(a[0] == '$') {
                bool flag = true;
                if(a.size() == 1) {
                    ans += a;
                    flag = false;
                }
                for(int i = 1; i < a.size(); i++) {
                    if(!isdigit(a[i])) {
                        ans += a;
                        flag = false;
                        break;
                    }
                }
                
                if(flag) {
                    double price = stod(a.substr(1));
                    price *= ((double)(100 - discount) / 100.0);
                    price = round(price * 100.0) / 100.0;
                    ans += "$" + to_string_with_precision(price, 2);
                }
                
            } else {
                ans += a;
            }
            ans += " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
    
private:
    template <typename T>
    string to_string_with_precision(const T a_value, const int n = 6)
    {
        std::ostringstream out;
        out.precision(n);
        out << std::fixed << a_value;
        return out.str();
    }
};
