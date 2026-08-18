class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if(k==n) return *max_element(nums.begin(), nums.end());

        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        int maxi = -1;

        if(k==1){
            for(int i=0; i<n; i++){
                if(mpp[nums[i]]==1) maxi = max(maxi, nums[i]);
            }
        }

        if(mpp[nums[0]]==1) maxi = max(maxi, nums[0]);
        
        if(mpp[nums[n-1]]==1) maxi = max(maxi, nums[n-1]);

        return maxi;
    }
};