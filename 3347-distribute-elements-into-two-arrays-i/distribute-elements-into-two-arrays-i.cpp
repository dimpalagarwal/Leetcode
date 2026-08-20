class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> array1;
        vector<int> array2;

        array1.push_back(nums[0]);
        array2.push_back(nums[1]);

        for(int i=2; i<n; i++){
            if(array1.back() > array2.back()) array1.push_back(nums[i]);
            else array2.push_back(nums[i]);
        }

        vector<int> ans;
        int l = array1.size();
        int k = array2.size();

        for(int i=0; i<l; i++){
            ans.push_back(array1[i]);
        }

        for(int i=0; i<k; i++){
            ans.push_back(array2[i]);
        }

        return ans;
    }
};