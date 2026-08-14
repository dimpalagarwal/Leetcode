class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int r = 0;

        int maxLen = INT_MIN;

        unordered_map<int, int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp[nums[r]] > k){
                maxLen = max(maxLen, r-l);
                mpp[nums[l]]--;
                l++;
            }
            r++;
        }

        maxLen = max(maxLen, r-l);

        return maxLen;
    }
};