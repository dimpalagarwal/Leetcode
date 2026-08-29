class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        int grpNum = 0;
        unordered_map<int,int> numToGrp;
        numToGrp[vec[0]] = grpNum;

        unordered_map<int, list<int>> grpToList;
        grpToList[grpNum].push_back(vec[0]);

        for(int i=1; i<n; i++){
            int diff = abs(vec[i]-vec[i-1]);
            if(diff > limit){
                grpNum++;
            }
            numToGrp[vec[i]] = grpNum;
            grpToList[grpNum].push_back(vec[i]);
        }

        for(int i=0; i<n; i++){
            int num = nums[i];
            int grpNumber = numToGrp[num];

            nums[i] = *(grpToList[grpNumber].begin());
            grpToList[grpNumber].pop_front();
        }

        return nums;
    }
};