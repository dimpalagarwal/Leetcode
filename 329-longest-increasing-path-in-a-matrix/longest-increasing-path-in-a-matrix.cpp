class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}};
    int helperFunction(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(dp[row][col]!=-1) return dp[row][col];

        int maxi = 1;

        for(int i=0; i<4; i++){
            int nrow = row + dirs[i][0];
            int ncol = col + dirs[i][1];

            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && matrix[nrow][ncol]>matrix[row][col]) maxi = max(maxi, 1+helperFunction(matrix, nrow, ncol, dp));
        }

        return dp[row][col] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxi = 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                maxi = max(maxi, helperFunction(matrix, i, j, dp));
            }
        }

        return maxi;
    }
};