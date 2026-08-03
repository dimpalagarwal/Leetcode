class Solution {
public:
    int AliceScore(vector<int>& stoneValue, int i, int n, vector<int> &dp){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];

        int take_one = stoneValue[i] + min(AliceScore(stoneValue, i+2, n, dp),min(AliceScore(stoneValue, i+3, n, dp), AliceScore(stoneValue, i+4, n, dp)));

        int take_two = (i + 1 < n) ? (stoneValue[i] + stoneValue[i+1] + min(AliceScore(stoneValue, i+3, n, dp), min(AliceScore(stoneValue, i+4, n, dp), AliceScore(stoneValue, i+5, n, dp)))) : INT_MIN;

        int take_three = (i + 2 < n) ? (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] + min(AliceScore(stoneValue, i+4, n, dp), min(AliceScore(stoneValue, i+5, n, dp), AliceScore(stoneValue, i+6, n, dp)))) : INT_MIN;

        return dp[i] = max(take_one, max(take_two, take_three));
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        int total_value = 0;
        for(int i=0; i<n; i++){
            total_value = total_value + stoneValue[i];
        }

        vector<int> dp(n, -1);

        int AliceSc = AliceScore(stoneValue, 0, n, dp);
        int BobSc = total_value-AliceSc;

        if(AliceSc == BobSc) return "Tie";
        else if(AliceSc > BobSc) return "Alice";

        return "Bob";
    }
};