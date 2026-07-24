class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int xorr = nums[i]^nums[j];
                st.insert(xorr);
            }
        }

        unordered_set<int> st2;
        for(int i=0; i<n; i++){
            for(auto &it: st){
                int xorr = it^nums[i];
                st2.insert(xorr);
            }
        }

        int count = st2.size();

        return count;
    }
};