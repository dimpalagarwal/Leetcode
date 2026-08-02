class Solution {
public:
    int helperFunction(vector<int>& piles, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i = piles[i] + min(helperFunction(piles, i+2, j, dp), helperFunction(piles, i+1, j-1, dp));
        int take_j = piles[j] + min(helperFunction(piles, i+1, j-1, dp), helperFunction(piles, i, j-2, dp));

        return dp[i][j] = max(take_i, take_j);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int sum = accumulate(piles.begin(), piles.end(), 0);

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int alice = helperFunction(piles, 0, n-1, dp);
        int bob = sum - alice;

        if(bob > alice) return false;
        return true;
    }
};