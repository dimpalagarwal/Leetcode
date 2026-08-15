class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xorr = 0;
        bool allZero = true;
        for(int i=0; i<n; i++){
            xorr = xorr ^ nums[i];
            if(nums[i]!=0) allZero = false;
        }

        if(allZero) return 0;
        return xorr == 0? n-1:n;
    }
};