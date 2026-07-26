class Solution {
public:
    int maximumProduct(vector<int>& nums) {
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

        int thirdMaxi = INT_MIN;
        bool maxSkipped = false;
        bool secMaxSkipped = false;

        for(int i=0; i<n; i++){
            if(nums[i]==maxi && !maxSkipped){
                maxSkipped = true;
                continue;
            }else if(nums[i]==secondMaxi && !secMaxSkipped){
                secMaxSkipped = true;
                continue;
            }

            thirdMaxi = max(thirdMaxi, nums[i]);
        }

        int potentialAns1 = maxi * secondMaxi * thirdMaxi;

        int mini = INT_MAX;
        int secondMini = INT_MIN;

        for(int i=0; i<n; i++){
            if(nums[i] < mini){
                secondMini = mini;
                mini = nums[i];
            }else if(nums[i] < secondMini){
                secondMini = nums[i];
            }
        }

        int potentialAns2 = maxi * secondMini * mini;

        int ans = max(potentialAns2, potentialAns1);

        return ans;
    }
};