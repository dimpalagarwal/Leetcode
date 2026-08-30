class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minPos = -1;
        int maxPos = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxPos = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                minPos = i;
            }
        }

        int ans = INT_MAX;
        if(minPos < maxPos){
            ans = min(ans, maxPos + 1);
            ans = min(ans, n-minPos);
            ans = min(ans, minPos+1+n-maxPos);
        }else{
            ans = min(ans, minPos + 1);
            ans = min(ans, n-maxPos);
            ans = min(ans, maxPos+1+n-minPos);
        }

        return ans;
    }
};