class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int active = count(s.begin(), s.end(), '1');

        vector<int> inactiveBlocks;
        int i = 0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i]=='0') i++;

                inactiveBlocks.push_back(i-start);
            }else{
                i++;
            }
        }

        int maxPairSum = 0;
        int m = inactiveBlocks.size();
        for(int i=1; i<m; i++){
            maxPairSum = max(maxPairSum, inactiveBlocks[i]+inactiveBlocks[i-1]);
        }

        return maxPairSum + active;
    }
};