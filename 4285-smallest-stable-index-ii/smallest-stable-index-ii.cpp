class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> minimums;
        int mini = INT_MAX;

        for(int i=n-1; i>=0; i--){
            mini = min(mini, nums[i]);
            minimums[i] = mini;
        }

        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            int score = maxi-minimums[i];

            if(score<=k) return i;
        }

        return -1;
    }
};