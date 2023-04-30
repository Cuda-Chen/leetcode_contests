// greedy
// WA

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int x1 = start[0], y1 = start[1], x2 = target[0], y2 = target[1];
        //int ans = abs(x2 - x1) + abs(y2 - y1);
        vector<vector<int>> s;
        for(int i = 0; i < specialRoads.size(); i++) {
            if(specialRoads[i][4] > (abs(specialRoads[i][2] - specialRoads[i][0]) + abs(specialRoads[i][3] - specialRoads[i][1])))
                continue;
            if((x1 <= specialRoads[i][0] && x2 >= specialRoads[i][2]) && (y1 <= specialRoads[i][1] && y2 >= specialRoads[i][3]))
                s.push_back(specialRoads[i]);
        }
        sort(s.begin(), s.end());
        int ans = 0;
        for(auto a : s) {
            int xx1 = a[0], yy1 = a[1], xx2 = a[2], yy2 = a[3], cost = a[4];
            if((x1 <= xx1 && x2 >= xx2) && (y1 <= yy1 && y2 >= yy2)) {
                ans += cost;
                ans += (abs(xx1 - x1) + abs(yy1 - y1));
                x1 = xx2;
                y1 = yy2;
            }
        }
        if(ans == 0) {
            ans += (abs(x2 - x1) + abs(y2 - y1));
        }
        return ans;
    }
};
