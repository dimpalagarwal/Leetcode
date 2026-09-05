class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int cnt = 1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                cnt++;
                if(cnt > 2){
                    nums.erase(nums.begin()+i);
                    i--;
                    n--;
                }
            }else{
                cnt = 1;
            }
        }

        return n;
    }
};