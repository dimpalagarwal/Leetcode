class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int secondMaxi = INT_MIN;

        for(int i=0; i<n; i++){
            if(nums[i] > maxi){
                secondMaxi = maxi;
                maxi = nums[i];
            }else if(nums[i] > secondMaxi){
                secondMaxi = nums[i];
            }
        }

        int ans = (maxi-1)*(secondMaxi-1);

        return ans;
    }
};