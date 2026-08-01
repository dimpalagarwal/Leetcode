class Solution {
public:
    int helperFunction(vector<int>& nums, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int take_i = nums[i] + min(helperFunction(nums, i+2, j, dp), helperFunction(nums, i+1, j-1, dp));
        int take_j = nums[j] + min(helperFunction(nums, i+1, j-1, dp), helperFunction(nums, i, j-2, dp));

        return dp[i][j] = max(take_i, take_j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(n,-1));

        int p1 = helperFunction(nums, 0, n-1, dp);
        int p2 = sum-p1;

        if(p1 >= p2) return true;
        return false;
    }
};