class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(cnt1) {
                sum1 += (2 * player1[i]);
                if(player1[i] == 10)
                    cnt1 = 2;
                else
                    cnt1--;
            } else {
                sum1 += player1[i];
                if(player1[i] == 10)
                    cnt1 = 2;
            }
            
            if(cnt2) {
                sum2 += (2 * player2[i]);
                if(player2[i] == 10)
                    cnt2 = 2;
                else
                    cnt2--;
            } else {
                sum2 += player2[i];
                if(player2[i] == 10)
                    cnt2 = 2;
            }
        }
        
        if(sum1 > sum2) 
            return 1;
        else if(sum2 > sum1)
            return 2;
        return 0;
    }
};
