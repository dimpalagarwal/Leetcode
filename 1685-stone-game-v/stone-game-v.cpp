class Solution {
public:
    int helperFunction(vector<int>& stoneValue, int i, int j, vector<vector<int>> &dp){
        if(i>=j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int totalSum = 0;
        for(int idx=i; idx<=j; idx++){
            totalSum += stoneValue[idx];
        }

        int maxi = 0;
        int sum = 0;
        for(int idx=i; idx<j; idx++){
            sum = sum + stoneValue[idx];
            int resSum = totalSum - sum;

            int ans = 0;
            if(resSum > sum) ans = sum + helperFunction(stoneValue, i, idx, dp);
            else if(resSum < sum) ans = resSum + helperFunction(stoneValue, idx+1, j, dp);
            else{
                int left = sum + helperFunction(stoneValue, i, idx, dp);
                int right = sum + helperFunction(stoneValue, idx+1, j, dp);

                ans = max(left, right);
            }

            maxi = max(maxi, ans);
        }

        return dp[i][j] = maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helperFunction(stoneValue, 0, n-1, dp);
    }
};