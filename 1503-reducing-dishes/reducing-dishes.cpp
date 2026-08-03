class Solution {
public:
    int helperFunction(vector<int>& satisfaction, int idx, int time, vector<vector<int>> &dp){
        if(idx >= satisfaction.size()) return 0;

        if(dp[idx][time]!=-1) return dp[idx][time];

        int take = time*satisfaction[idx] + helperFunction(satisfaction, idx+1, time+1, dp);
        int skip = helperFunction(satisfaction, idx+1, time, dp);

        return dp[idx][time] = max(take, skip);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helperFunction(satisfaction, 0, 1, dp);
    }
};