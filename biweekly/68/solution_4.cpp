// https://leetcode.com/problems/abbreviating-the-product-of-a-range/discuss/1646713/Java-Keep-track-of-the-product-start-and-end
// keep track of product start and end

class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long nzeros = 0;
        long end = 1;
        bool usedMod = false;
        for(int i = left; i <= right; i++) {
            end *= i;
            while(end % 10 == 0) {
                end /= 10;
                nzeros++;
            }
            if(end >= 1000000000000L) {
                end %= 1000000000000L;
                usedMod = true;
            }
        }
        if(!usedMod && end < 10000000000L)
            return to_string(end) + "e" + to_string(nzeros);
        
        long start = 1;
        for(int i = left; i <= right; i++) {
            start *= i;
            
            while(start >= 1000000000000L)
                start /= 10;
        }
        
        return build(usedMod, start, end, nzeros);
    }
    
private:
    string build(bool usedMod, long start, long end, long nzeros) {
        while(start >= 100000)
            start /= 10;
        
        end %= 100000;
        string endString = to_string(end);
        while(endString.size() < 5)
            endString = "0" + endString;
        
        return to_string(start) + "..." + endString + "e" + to_string(nzeros);
    }
};
